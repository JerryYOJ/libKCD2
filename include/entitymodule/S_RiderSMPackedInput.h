#pragma once
#include <cstdint>
#include <cstddef>
#include "E_RiderGait.h"
#include "E_RiderInputBits.h"

// -----------------------------------------------
// wh::entitymodule::S_RiderSMPackedInput -- KCD2 WHGame.dll.  sizeof 0x18.
// -----------------------------------------------
// [SYNTHETIC] no TypeDescriptor. Per-tick input built on Update stack, filled by
// PackSMInput / FillForcedState, copied onto S_RiderSMInput+0x04 by Tick.
// Init qword at +0x10 is 0x805000000 (maxGait=5, forcedState=8).

namespace wh::entitymodule {

struct S_RiderSMPackedInput {
    float    m_dt;            // +0x00  Update dt
    float    m_stickMag;      // +0x04  Input+0xA0C
    float    m_moveX;         // +0x08
    float    m_moveY;         // +0x0C
    uint8_t  m_inputBits;     // +0x10  E_RiderInputBits flags
    uint8_t  m_inputBits1;    // +0x11  bit0 horse physically in gait 3/4; bit1 bonding (FillForcedState)
    uint8_t  m_minGait;       // +0x12
    uint8_t  m_maxGait;       // +0x13  init 5
    E_RiderGait::Type m_forcedState; // +0x14  None=8 when unset
    uint8_t  _pad15[3];       // +0x15
};
static_assert(sizeof(S_RiderSMPackedInput) == 0x18, "S_RiderSMPackedInput must be 0x18");
static_assert(offsetof(S_RiderSMPackedInput, m_forcedState) == 0x14, "forced");

}  // namespace wh::entitymodule
