#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_RiderInputBits -- S_RiderSMPackedInput::m_inputBits flags (KCD2 WHGame.dll).
// -----------------------------------------------
// [SYNTHETIC] reconstructed from the producer PackSMInput 0x180A4F304 and the gait-SM
// consumers (dispatch 0x181ECAF60; state handlers 0x18126E90C / 0x18126E9C0 / 0x18126E7FC /
// 0x1829F1998 / 0x1829F183C). SpeedupHeld climbs are RISING-EDGE tests against the previous
// frame's copy at S_RiderSMInput+0x14 (one gait per fresh press / one dash pump per spur).

namespace wh::entitymodule {

struct E_RiderInputBits {
    enum Type : uint8_t {
        Jump        = 0x01,  // <- input+0x9C5; Forward+this while Stand -> Jump(7)
        WalkMod     = 0x02,  // <- input+0x9C6; scales forward x0.15 in wants-walk test 0x18126EC6C
        Forward     = 0x04,  // m_move.y >= 0.25 (or external forward drive >= 1)
        Backward    = 0x08,  // m_move.y <= -0.25 (or external drive <= -1)
        SpeedupHeld = 0x10,  // <- input+0x9C7; edge climbs one gait / pumps the dash reservoir
        DoubleTap   = 0x20,  // <- input+0x9C9 one-shot; Idle2Move -> instant Dash + reservoir init
        // 0x40 unobserved
        Slowdown    = 0x80,  // <- input+0x9C8 one-shot; downshifts Sprint/Dash one gait
    };
};

}  // namespace wh::entitymodule
