#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"
#include <vector>
#include "S_CombatHitSubInfo.h"

namespace wh::combatmodule {
class C_CombatHitInfo {
public:
    RTTR_ENABLE()  // [0..2]
    std::int32_t m_bodySubpartId;  // +0x8 RTTR "BodySubpartId"
    float m_attackCoef;  // +0xC RTTR "AttackCoef"
    std::int32_t m_handSlot;  // +0x10 RTTR "HandSlot"
    std::uint8_t m_unknown14[0x4];                  // +0x14
    std::vector<S_CombatHitSubInfo> m_subInfos;  // +0x18 RTTR "SubInfos"
};

static_assert(offsetof(C_CombatHitInfo, m_subInfos) == 0x18, "C_CombatHitInfo::m_subInfos offset mismatch");
static_assert(offsetof(C_CombatHitInfo, m_handSlot) == 0x10, "C_CombatHitInfo::m_handSlot offset mismatch");
static_assert(offsetof(C_CombatHitInfo, m_attackCoef) == 0xc, "C_CombatHitInfo::m_attackCoef offset mismatch");
static_assert(offsetof(C_CombatHitInfo, m_bodySubpartId) == 0x8, "C_CombatHitInfo::m_bodySubpartId offset mismatch");
static_assert(sizeof(C_CombatHitInfo) == 0x30, "C_CombatHitInfo size mismatch");

}  // namespace wh::combatmodule
