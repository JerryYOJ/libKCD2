#include "TruffleHoundMutt.h"

#include <unordered_map>

#include "crysystem/SSystemGlobalEnvironment.h"
#include "cry3dengine/CParticleEmitter.h"
#include "Offsets/vtables/IParticleEffect.h"
#include "Offsets/vtables/IParticleEmitter.h"
#include "Offsets/vtables/IParticleManager.h"
#include "entitymodule/C_Item.h"
#include "entitymodule/C_ItemDatabase.h"
#include "entitymodule/C_ItemManager.h"
#include "entitymodule/S_FoodItemClass.h"
#include "entitymodule/S_HerbItemClass.h"
#include "entitymodule/S_ItemClass.h"
#include "environmentmodule/C_EnvironmentModule.h"
#include "environmentmodule/C_PickableAreaDatabase.h"
#include "environmentmodule/C_PickableAreaInstanceGrid.h"
#include "environmentmodule/C_RespawnManager.h"
#include "framework/GuidUtils.h"
#include "rpgmodule/C_Soul.h"
#include "rpgmodule/C_SoulList.h"
#include "xgenaimodule/C_NPC.h"
#include "xgenaimodule/C_SearchItemDogObjective.h"

#include "mcm.h"

namespace TruffleHoundMutt {
namespace {

using wh::entitymodule::C_ItemDatabase;
using wh::entitymodule::C_ItemManager;
using wh::environmentmodule::C_EnvironmentModule;
using wh::environmentmodule::C_PickableAreaDatabase;
using wh::rpgmodule::C_SoulList;
using wh::xgenaimodule::activitysystem::C_DogObjective;
using wh::xgenaimodule::activitysystem::C_SearchItemDogObjective;
using wh::xgenaimodule::activitysystem::E_DogObjective;

// perk__trufflehoundmutt.xml perk_id (Truffle Hound, Houndmaster tree, level 8).
constexpr const char* kPerkIdTruffleHound = "f9c4c980-e46f-4d67-a93a-f44efe10242d";

// Fresh and dried yield GUIDs both key straight to the pickable_area_desc row id.
std::unordered_map<CryGUID, uint8_t> s_guidToArea;

float DistSq(const Vec3& a, const Vec3& b)
{
    const float dx = a.x - b.x;
    const float dy = a.y - b.y;
    const float dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}

CryGUID DriedCounterpart(C_ItemDatabase* items, const CryGUID& yield)
{
    if (auto* cls = items ? items->FindClassByGuid(yield) : nullptr) {
        if (auto* herb = cls->GetAsHerbItemClass())
            return herb->m_driedItemId;
        if (auto* food = cls->GetAsFoodItemClass())
            return food->m_driedItemId;
    }
    return {};
}

bool PerkSatisfied()
{
    if (!g_requirePerk)
        return true;
    auto* souls = C_SoulList::GetInstance();
    auto* soul = souls ? souls->LookupByWUID(souls->m_playerSoulWuid) : nullptr;
    CryGUID perkId{};
    return soul && wh::ParseGuid(kPerkIdTruffleHound, perkId) && soul->HasPerk(perkId);
}

bool GetDogOrigin(C_SearchItemDogObjective* self, Vec3& out)
{
    auto* npc = self->m_pActivityContext ? self->m_pActivityContext->GetNPC() : nullptr;
    const Vec3* origin = npc ? npc->UpdateCachedTransform() : nullptr;
    if (!origin)
        return false;
    out = *origin;
    return true;
}

bool FindNearestAvailablePlant(uint8_t areaId, const Vec3& origin, Vec3& out)
{
    auto* env = C_EnvironmentModule::GetInstance();
    auto* rm = env ? env->GetRespawnManager() : nullptr;
    if (!rm || !rm->m_pInstanceGrid)
        return false;

    const float maxR2 = g_maxRange > 0.f ? g_maxRange * g_maxRange : 0.f;
    bool found = false;
    float best = 0.f;
    for (const auto& cell : rm->m_pInstanceGrid->m_cells) {
        for (const auto& inst : cell.second) {
            if (!inst.available || inst.pickable_area_id != areaId)
                continue;
            const float d2 = DistSq(origin, inst.position);
            if (maxR2 > 0.f && d2 > maxR2)
                continue;
            if (!found || d2 < best) {
                found = true;
                best = d2;
                out = inst.position;
            }
        }
    }
    return found;
}

// ---- plant beacon (trufflehoundmutt.plant_shaft) ---------------------------

Offsets::IParticleEmitter* s_beacon = nullptr;

Offsets::IParticleEffect* BeaconEffect()
{
    // Cache only on success: a failed FindEffect can intern an empty stub.
    static Offsets::IParticleEffect* fx = nullptr;
    if (fx)
        return fx;
    auto* env = SSystemGlobalEnvironment::GetInstance();
    if (!env || !env->pParticleManager)
        return nullptr;
    fx = env->pParticleManager->FindEffect("trufflehoundmutt.plant_shaft",
                                           "TruffleHoundMutt", true);
    return fx;
}

void SpawnPlantBeacon(const Vec3& pos)
{
    KillPlantBeacon();
    auto* fx = BeaconEffect();
    if (!fx)
        return;
    // Same pose Lua Particle.SpawnEffect(..., {x=0,y=0,z=1}) builds: SetRotationVDir
    // maps the emitter's local Y (CryEngine particle forward) onto world +Z.
    auto* e = fx->Spawn(QuatTS(Quat::CreateRotationVDir(Vec3(0.f, 0.f, 1.f)), pos, 1.f), 0);
    if (!e)
        return;
    static_cast<CParticleEmitter*>(e)->AddRef();  // our ref; Spawn's ref belongs to the manager
    s_beacon = e;
}

// C_Signal<unsigned> subscriber; fired by the objective-end funnel on natural
// completion AND on interrupts (StopIfRunning routes through the same funnel).
void OnObjectiveComplete(C_DogObjective* objective, unsigned /*result*/)
{
    if (objective)
        objective->m_onComplete.Disconnect(objective, &OnObjectiveComplete);
    KillPlantBeacon();
}

}  // namespace

void RegisterYields()
{
    s_guidToArea.clear();

    auto* db = C_PickableAreaDatabase::GetInstance();
    if (!db)
        return;

    auto* items = C_ItemDatabase::GetInstance();
    for (const auto& area : db->m_objects) {
        const CryGUID& yield = area.guid_item_picked;
        if (yield == CryGUID{})
            continue;
        s_guidToArea[yield] = area.id;

        const CryGUID dried = DriedCounterpart(items, yield);
        if (dried != CryGUID{}) {
            // emplace: if a dried GUID is also some area's own yield, the fresh
            // mapping wins regardless of row order.
            s_guidToArea.emplace(dried, area.id);
        }
    }
}

bool AllowHerb(const CryGUID& classGuid)
{
    return s_guidToArea.count(classGuid) != 0 && PerkSatisfied();
}

void KillPlantBeacon()
{
    auto* e = s_beacon;
    if (!e)
        return;
    s_beacon = nullptr;
    e->Kill();
    static_cast<CParticleEmitter*>(e)->Release();
}

bool TryHerbTrack(C_SearchItemDogObjective* self)
{
    if (!self)
        return false;
    auto* items = C_ItemManager::GetInstance();
    auto* item = items ? items->LookupByWUID(self->m_item) : nullptr;
    auto* cls = item ? item->GetClassData() : nullptr;
    if (!cls)
        return false;

    const auto it = s_guidToArea.find(cls->m_guid);
    if (it == s_guidToArea.end())
        return false;
    // Without the perk a map GUID can only reach here through a vanilla sniffable
    // entry (quest items) -- leave those to the vanilla picker.
    if (!PerkSatisfied())
        return false;

    Vec3 origin, dest;
    if (GetDogOrigin(self, origin) && FindNearestAvailablePlant(it->second, origin, dest)) {
        self->CommitDestination(dest);
        if (g_showBeacon) {
            SpawnPlantBeacon(dest);
            // CommitDestination completes SearchItem immediately after queueing type 7
            // (Search=7 is the walk/bark objective). Subscribe to THAT pooled object.
            if (auto* search = self->FindByType(
                    wh::xgenaimodule::activitysystem::E_DogObjective::Search))
                search->m_onComplete.Connect(search, &OnObjectiveComplete);
        }
    } else {
        self->Fail();
    }
    return true;
}

}  // namespace TruffleHoundMutt
