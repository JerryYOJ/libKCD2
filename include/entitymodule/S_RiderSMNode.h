#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::entitymodule::S_RiderSMNode -- KCD2 WHGame.dll.  sizeof 0xE8.
// -----------------------------------------------
// [SYNTHETIC] no TypeDescriptor. 8-element SSO pool at C_RiderStateMachine+0xF0.
// Size from sub_180A2ED2C (return 0xE8 * n). Contents UNVERIFIED.

namespace wh::entitymodule {

struct S_RiderSMNode {
    uint8_t m_storage[0xE8];
};
static_assert(sizeof(S_RiderSMNode) == 0xE8, "S_RiderSMNode must be 0xE8");

}  // namespace wh::entitymodule
