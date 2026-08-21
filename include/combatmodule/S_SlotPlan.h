#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/TimeValue.h"

namespace wh::combatmodule {

struct S_SlotPlan {
    CTimeValue    m_fireAt;        // +0x00
    float         m_windowDuration;// +0x08
    std::uint32_t _pad0C;          // +0x0C
};
static_assert(sizeof(S_SlotPlan) == 0x10);
static_assert(offsetof(S_SlotPlan, m_fireAt) == 0x00);
static_assert(offsetof(S_SlotPlan, m_windowDuration) == 0x08);

}  // namespace wh::combatmodule
