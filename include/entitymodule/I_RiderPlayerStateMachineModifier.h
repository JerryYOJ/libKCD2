#pragma once
#include <cstdint>
#include "S_RiderSMPackedInput.h"
#include "S_RiderSMOutput.h"

// -----------------------------------------------
// wh::entitymodule::I_RiderPlayerStateMachineModifier -- KCD2 WHGame.dll.  sizeof 8.  2 slots.
// -----------------------------------------------
// RTTI .?AUI_RiderPlayerStateMachineModifier@entitymodule@wh@@.
// Secondary base of S_OnPressController at +8 (vt 0x183C348D0).
// C_RiderPlayerInput+0x9A8 is a vector of these. Tick ABI:
//   [0] (this, smInput[0], S_RiderSMPackedInput*)
//   [1] (this, smInput[0], S_RiderSMOutput*)
// Handlers receive the +8 this.

namespace wh::entitymodule {

class I_RiderPlayerStateMachineModifier {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_RiderPlayerStateMachineModifier;
    virtual void OnGaitHint(uint8_t gait, S_RiderSMPackedInput* packed) = 0; // [0] 0x180A4ECEC
    virtual void OnStateOutput(uint8_t gait, S_RiderSMOutput* out) = 0;      // [1] 0x181ECC460
};
static_assert(sizeof(I_RiderPlayerStateMachineModifier) == 8, "I_RiderPlayerStateMachineModifier is vtable-only");

}  // namespace wh::entitymodule
