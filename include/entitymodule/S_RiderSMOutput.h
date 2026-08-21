#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::entitymodule::S_RiderSMOutput -- KCD2 WHGame.dll.  sizeof 2.
// -----------------------------------------------
// [SYNTHETIC] no TypeDescriptor. WORD written by S_RiderSMInput::SetState.
// Tick returns this; Update keeps a stack copy and stores it at Input+0x9E4.

namespace wh::entitymodule {

struct S_RiderSMOutput {
    uint8_t m_gaitBits;  // +0x00  Walk/Run/Sprint/Dash/Jump/ForcedRear
    uint8_t m_spurBits;  // +0x01  FastSlowDown/DashSpur/SprintSpur
};
static_assert(sizeof(S_RiderSMOutput) == 2, "S_RiderSMOutput must be 2");

}  // namespace wh::entitymodule
