#pragma once
#include <cstddef>
#include <cstdint>
#include "../framework/WUID.h"

namespace wh::xgenaimodule {

// Non-polymorphic C_NPC subobject initialized by 0x180BDCAC4. Its exact source
// role is OPEN; only the WUID-bearing first field is currently named.
struct S_NPCWuidState {
    framework::WUID m_wuid;       // +0x00
    std::uint64_t _unknown08;     // +0x08
    std::uint64_t _unknown10;     // +0x10
    std::uint64_t _unknown18;     // +0x18
    bool _flag20;                 // +0x20
    std::uint8_t _pad21[7];       // +0x21
};
static_assert(sizeof(S_NPCWuidState) == 0x28,
              "S_NPCWuidState must be 0x28");
static_assert(offsetof(S_NPCWuidState, m_wuid) == 0x00,
              "NPC WUID state must begin with its WUID");

}  // namespace wh::xgenaimodule
