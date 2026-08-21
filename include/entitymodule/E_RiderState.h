#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_RiderState -- RTTR enum (KCD2 WHGame.dll).
// -----------------------------------------------
// Rider mount/anim phases, NOT the gait SM (that is E_RiderGait).
// Values from RTTR registration (LuaUtils E_RiderState::Type).

namespace wh::entitymodule {

struct E_RiderState {
    enum Type : int32_t {
        none           = 0,
        mount          = 1,
        mounted        = 2,
        dismount       = 3,
        idle2move      = 4,
        move2idle      = 5,
        fastStop       = 6,
        rear           = 7,
        forcedRear     = 8,
        jump           = 9,
        land           = 10,
        bondingSaddle  = 11,
        bondingGround  = 12,
    };
};

}  // namespace wh::entitymodule
