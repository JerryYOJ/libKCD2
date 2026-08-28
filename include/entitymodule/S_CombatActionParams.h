#pragma once

#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

struct S_CombatActionParams {
    bool m_unknown00;                                                    // +0x00 ctor-zeroed
    std::uint8_t m_padding01[7];                                         // +0x01
    bool m_highPriority;                                                 // +0x08 slot 37: SetPriority(byte ? 2 : 1)
    std::uint8_t m_padding09[7];                                         // +0x09
};

static_assert(offsetof(S_CombatActionParams, m_unknown00) == 0x00,
              "S_CombatActionParams::m_unknown00 offset mismatch");
static_assert(offsetof(S_CombatActionParams, m_highPriority) == 0x08,
              "S_CombatActionParams::m_highPriority offset mismatch");
static_assert(sizeof(S_CombatActionParams) == 0x10,
              "S_CombatActionParams size mismatch");

} // namespace wh::entitymodule
