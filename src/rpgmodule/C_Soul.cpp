#include "rpgmodule/C_Soul.h"
#include "rpgmodule/C_SoulList.h"
#include "rpgmodule/C_RPGModule.h"
#include "Offsets/Offsets.h"
#include "Offsets/vtables/IEntitySystem.h"
#include "Offsets/vtables/IEntity.h"
#include "crysystem/SSystemGlobalEnvironment.h"

// C_Soul / C_SoulList engine-function forwarders. Thin wrappers around verified
// KCD2 1.5.6 RVAs (mirrors C_FactionManager.cpp).

namespace wh { namespace rpgmodule {

C_SoulList* C_SoulList::GetInstance()
{
    C_RPGModule* rpg = C_RPGModule::GetInstance();
    return rpg ? rpg->m_pSoulList : nullptr;   // ctor-owned, C_RPGModule+0x80
}

C_Soul* C_SoulList::LookupByWUID(const wh::framework::WUID& wuid)
{
    // sub_181F985D0(&m_soulTable, &wuid) -- the exact call the script-bind soul
    // resolver makes (sub_18041ED20: "__ThisWUID" -> RPGModule+0x80, table @+0x38).
    using Fn = C_Soul* (__fastcall*)(void*, const wh::framework::WUID*);
    static REL::Relocation<Fn> fn{ REL::Offset(0x1F985D0) };
    return fn(&m_soulTable, &wuid);
}

float C_Soul::GetDerivedStat(int statId) const
{
    // sub_180648B18(soul, statId, 0): derived-stat evaluator; float in xmm0.
    using Fn = float (__fastcall*)(const C_Soul*, int, int64_t);
    static REL::Relocation<Fn> fn{ REL::Offset(0x648B18) };
    return fn(this, statId, 0);
}

bool C_Soul::HasAbility(uint32_t abilityId) const
{
    // Worker sub_1809DCC70(block, out, id): binary-search of the sorted ability
    // block @soul+0x320 into a {bool present, u64 payload} result; ids 62/18 are
    // computed inside the worker, and the C_RPGModule cvar block's all-abilities
    // flag forces true. Ids 0 / 73 additionally gate on derived stat 186 / 187
    // (mirrors the Lua HasAbility handler 0x182CF7D88).
    struct S_Result { bool present; uint8_t _pad[7]; uint64_t payload; };
    using Fn = S_Result* (__fastcall*)(const void*, S_Result*, uint32_t);
    static REL::Relocation<Fn> fn{ REL::Offset(0x9DCC70) };
    S_Result r{};
    fn(reinterpret_cast<const uint8_t*>(this) + 0x320, &r, abilityId);
    if (abilityId == 0)
        return r.present && GetDerivedStat(186) > 0.0f;
    if (abilityId == 73)
        return r.present && GetDerivedStat(187) > 0.0f;
    return r.present;
}

Offsets::IEntity* C_Soul::GetBoundEntity() const
{
    auto* env = SSystemGlobalEnvironment::GetInstance();
    if (!env || !env->pEntitySystem)
        return nullptr;

    const uint32_t id = env->pEntitySystem->FindEntityByGuid(m_entityGuid);
    return id ? env->pEntitySystem->GetEntity(id) : nullptr;
}

}}  // namespace wh::rpgmodule
