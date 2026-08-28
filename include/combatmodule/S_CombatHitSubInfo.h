#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::combatmodule {
class S_CombatHitSubInfo {
public:
    virtual ~S_CombatHitSubInfo();
    RTTR_ENABLE()  // [1..3]
    std::int32_t m_oppGuardStanceId;  // +0x8 RTTR "OppGuardStanceId"
    std::uint8_t m_unknown0C[0x4];                  // +0xC
    CryStringT<char> m_oppWeaponCombination;  // +0x10 RTTR "OppWeaponCombination"
    std::int32_t m_bodySubpartId;  // +0x18 RTTR "BodySubpartId"
    float m_attackCoef;  // +0x1C RTTR "AttackCoef"
};

static_assert(offsetof(S_CombatHitSubInfo, m_attackCoef) == 0x1c, "S_CombatHitSubInfo::m_attackCoef offset mismatch");
static_assert(offsetof(S_CombatHitSubInfo, m_bodySubpartId) == 0x18, "S_CombatHitSubInfo::m_bodySubpartId offset mismatch");
static_assert(offsetof(S_CombatHitSubInfo, m_oppWeaponCombination) == 0x10, "S_CombatHitSubInfo::m_oppWeaponCombination offset mismatch");
static_assert(offsetof(S_CombatHitSubInfo, m_oppGuardStanceId) == 0x8, "S_CombatHitSubInfo::m_oppGuardStanceId offset mismatch");
static_assert(sizeof(S_CombatHitSubInfo) == 0x20, "S_CombatHitSubInfo size mismatch");

}  // namespace wh::combatmodule
