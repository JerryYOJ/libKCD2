#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_RiderGait -- C_RiderStateMachine state byte (KCD2 WHGame.dll).
// -----------------------------------------------
// [SYNTHETIC] reconstructed from dispatch sub_181ECAF60 + set-state sub_18126EAD4
// + logical-speed tags sub_180BE2E7C. Not an RTTR enum. Stored as one byte (SM+0).
// HorseSprint/HorseDash are the mannequin tag names; there is no SM name "trot"/"gallop".

namespace wh::entitymodule {

struct E_RiderGait {
    enum Type : uint8_t {
        Stand       = 0,
        Idle2Move   = 1,
        Walk        = 2,
        Run         = 3,
        HorseSprint = 4,
        HorseDash   = 5,
        ForcedRear  = 6,
        Jump        = 7,
        None        = 8,   // forced-state sentinel, not a gait
    };
};

}  // namespace wh::entitymodule
