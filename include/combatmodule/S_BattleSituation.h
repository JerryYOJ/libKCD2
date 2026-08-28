#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::combatmodule {
class S_BattleSituation {
public:
    virtual ~S_BattleSituation();
    RTTR_ENABLE()  // [1..3]
    std::int32_t m_totalCount;  // +0x8 RTTR "TotalCount"
    std::int32_t m_aliveCount;  // +0xC RTTR "AliveCount"
    std::int32_t m_deadCount;  // +0x10 RTTR "DeadCount"
    std::uint8_t m_unknown14[0x4];                  // +0x14
};

static_assert(offsetof(S_BattleSituation, m_deadCount) == 0x10, "S_BattleSituation::m_deadCount offset mismatch");
static_assert(offsetof(S_BattleSituation, m_aliveCount) == 0xc, "S_BattleSituation::m_aliveCount offset mismatch");
static_assert(offsetof(S_BattleSituation, m_totalCount) == 0x8, "S_BattleSituation::m_totalCount offset mismatch");
static_assert(sizeof(S_BattleSituation) == 0x18, "S_BattleSituation size mismatch");

}  // namespace wh::combatmodule
