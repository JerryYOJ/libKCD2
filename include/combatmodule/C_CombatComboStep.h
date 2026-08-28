#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::combatmodule {
class C_CombatComboStep {
public:
    RTTR_ENABLE()  // [0..2]
    std::uint8_t m_unknown08[0x4];                  // +0x8
    std::int32_t m_guardZone;  // +0xC RTTR "GuardZone"
    std::uint8_t m_unknown10[0x4];                  // +0x10
    bool m_isCharged;  // +0x14 RTTR "IsCharged"
    bool m_useSolver;  // +0x15 RTTR "UseSolver"
    std::uint8_t m_unknown16[0xA];                  // +0x16
};

static_assert(offsetof(C_CombatComboStep, m_useSolver) == 0x15, "C_CombatComboStep::m_useSolver offset mismatch");
static_assert(offsetof(C_CombatComboStep, m_isCharged) == 0x14, "C_CombatComboStep::m_isCharged offset mismatch");
static_assert(offsetof(C_CombatComboStep, m_guardZone) == 0xc, "C_CombatComboStep::m_guardZone offset mismatch");
static_assert(sizeof(C_CombatComboStep) == 0x20, "C_CombatComboStep size mismatch");

}  // namespace wh::combatmodule
