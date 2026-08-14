#include <MinHook.h>

#include "KCSE/KCSEAPI.h"
#include "REL.h"

#include "crysystem/SSystemGlobalEnvironment.h"
#include "guimodule/E_MarkType.h"
#include "rpgmodule/C_RPGLocationManager.h"
#include "rpgmodule/I_POI.h"
#include "rpgmodule/S_POIType.h"

#include "mcm.h"
#include "persist.h"

namespace {

enum class DiscoverKind {
    Shop,
    Workstation,
    Service,
    Landmark,
    Wilderness,
    Secret,
    FastTravel,
};

DiscoverKind KindOf(wh::rpgmodule::I_RPGLocationManager* mgr, wh::rpgmodule::I_POI* poi)
{
    using M = wh::guimodule::E_MarkType::Type;
    const M mark = static_cast<M>(poi->GetMarkType());

    auto typeRow = [mgr, poi]() -> const wh::rpgmodule::S_POIType* {
        wh::rpgmodule::S_LocationId id{};
        poi->GetTypeId(id);
        return mgr->FindPOIType(id);
    };

    switch (mark) {
    case M::Shop:
    case M::Blacksmith:
    case M::Armourer:
    case M::Weaponsmiths:
    case M::Shoemaker:
    case M::Tailor:
    case M::Apothecary:
    case M::Herbalist:
    case M::Miller:
    case M::HorseTrader:
    case M::Saddler:
    case M::Bakery:
    case M::Butchery:
    case M::VegetableShop:
    case M::Tanner:
    case M::Hunter:
    case M::Scribe:
    case M::Gunsmith:
    case M::Barber:
    case M::ShieldPainter:
    case M::Smithy:
        return DiscoverKind::Shop;

    case M::Alchemy:
    case M::SharpeningWheel:
    case M::SmokingFood:
    case M::DryingFood:
    case M::DiceTable:
        return DiscoverKind::Workstation;

    case M::Washing: {
        const auto* def = typeRow();
        if (def && def->m_discoverableByLocation)
            return DiscoverKind::Shop;
        return DiscoverKind::Workstation;
    }

    case M::Pub:
    case M::Hotel:
    case M::Baths:
    case M::Bailiff:
    case M::Arena:
    case M::ArcheryArena:
    case M::FistFight:
    case M::Home:
    case M::Bed:
    case M::BedPlayer:
        return DiscoverKind::Service;

    case M::Grave:
    case M::ConcCross:
    case M::Shrine:
    case M::MineEnrtrance:
    case M::Nest:
    case M::Hive:
        return DiscoverKind::Landmark;

    case M::HuntingSpot:
    case M::HuntingSpotBoar:
    case M::HuntingSpotRoe:
    case M::HuntingSpotWolf:
    case M::FishingSpot:
    case M::ForestGarden:
    case M::Camp:
    case M::CampEnemy:
        return DiscoverKind::Wilderness;

    case M::FastTravel:
    case M::FastTravelLevel:
    case M::FastTravelSedlec:
        return DiscoverKind::FastTravel;

    default: {
        const auto* def = typeRow();
        if (def && def->m_discoverableByLocation)
            return DiscoverKind::Shop;
        return DiscoverKind::Secret;
    }
    }
}

float ScaleOf(DiscoverKind kind)
{
    switch (kind) {
    case DiscoverKind::Shop:        return g_shop;
    case DiscoverKind::Workstation: return g_workstation;
    case DiscoverKind::Service:     return g_service;
    case DiscoverKind::Landmark:    return g_landmark;
    case DiscoverKind::Wilderness:  return g_wilderness;
    case DiscoverKind::Secret:      return g_secret;
    case DiscoverKind::FastTravel:  return g_fastTravel;
    }
    return 1.f;
}

class {
public:
    static bool Install()
    {
        void* target = reinterpret_cast<void*>(REL::ID(51133).address());
        if (MH_CreateHook(target, reinterpret_cast<void*>(&DiscoverPOIsAtPosition),
                          reinterpret_cast<void**>(&orig)) != MH_OK)
            return false;
        return MH_EnableHook(target) == MH_OK;
    }

    static void Uninstall()
    {
        void* target = reinterpret_cast<void*>(REL::ID(51133).address());
        MH_RemoveHook(target);
    }

protected:
    static void DiscoverPOIsAtPosition(void*, const Vec3& pos)
    {
        auto* mgr = wh::rpgmodule::C_RPGLocationManager::GetInstance();
        if (!mgr)
            return;

        std::vector<wh::rpgmodule::I_POI*> pois;
        mgr->GetAllPOIs(pois);
        for (wh::rpgmodule::I_POI* poi : pois) {
            if (!poi)
                continue;
            Vec3 p;
            poi->GetPosition(p);
            float r = poi->GetRadius();
            if (r <= 0.f)
                r = mgr->GetDefaultPOIRadius();
            r *= ScaleOf(KindOf(mgr, poi));
            const float dx = pos.x - p.x;
            const float dy = pos.y - p.y;
            if (dx * dx + dy * dy <= r * r)
                poi->SetDiscoveredGated(false, false);
        }
    }

    static inline REL::Relocation<decltype(&DiscoverPOIsAtPosition)> orig;
} hkDiscoverPOIsAtPosition;

}  // namespace

KCSE_PLUGIN_INFO("Discovery Radius Expander", "JerryYOJ", 1);
KCSE_PLUGIN_LOAD(kcse)
{
    if (MH_Initialize() != MH_OK)
        return false;
    if (!hkDiscoverPOIsAtPosition.Install())
        return false;

    DRE::LoadPersistedEdits();
    MCM::ListenForMessages(&HandleMcmMessage);

    kcse->GetMessagingInterface()->RegisterListener([](KCSE::Message* msg) {
        if (msg->type != KCSE::IMessagingInterface::kMessage_DataLoaded)
            return;
        auto* env = SSystemGlobalEnvironment::GetInstance();
        if (!env || !env->pConsole)
            return;
        for (const auto& bind : kMcmBindings)
            env->pConsole->RegisterCVarFloat(bind.cvarName, bind.store, bind.defaultValue,
                                             VF_NULL, bind.tooltip);
    });
    return true;
}
