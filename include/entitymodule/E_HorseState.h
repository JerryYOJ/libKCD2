#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_HorseState -- RTTR enum (KCD2 WHGame.dll).
// -----------------------------------------------
// Mount/anim phases on the horse, NOT the gait SM (that is E_RiderGait).
// Values from RTTR registration (LuaUtils E_HorseState::Type).

namespace wh::entitymodule {

struct E_HorseState {
    enum Type : int32_t {
        idle           = 0,
        idle2move      = 1,
        move2idle      = 2,
        rear           = 3,
        forcedRear     = 4,
        fastStop       = 5,
        exhausted      = 6,
        jump           = 7,
        bondingSaddle  = 8,
        bondingGround  = 9,
        headNoResponse = 10,
        headHitting    = 11,
    };
};

}  // namespace wh::entitymodule
