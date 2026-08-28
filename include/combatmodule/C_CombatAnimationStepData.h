#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::combatmodule {
class C_CombatAnimationStepData {
public:
    RTTR_ENABLE()  // [0..2]
    CryStringT<char> m_name;  // +0x8 RTTR "Name"
    std::int32_t m_step;  // +0x10 RTTR "Step"
    std::uint8_t m_unknown14[0x4];                  // +0x14
};

static_assert(offsetof(C_CombatAnimationStepData, m_step) == 0x10, "C_CombatAnimationStepData::m_step offset mismatch");
static_assert(offsetof(C_CombatAnimationStepData, m_name) == 0x8, "C_CombatAnimationStepData::m_name offset mismatch");
static_assert(sizeof(C_CombatAnimationStepData) == 0x18, "C_CombatAnimationStepData size mismatch");

}  // namespace wh::combatmodule
