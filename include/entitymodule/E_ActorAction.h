#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_ActorAction {
    enum Type : std::uint8_t {
        idle       = 0,
        motion     = 1,
        transition = 2,
        jumpStart  = 3,
        jump       = 4,
        jumpEnd    = 5,
        ladder     = 6,
        ledge      = 7,
        dead       = 8,
        ai         = 9,
        mount      = 10,
        dismount   = 11,
        rear       = 12,
        fastStop   = 13,
        move2idle  = 14,
        idle2move  = 15,
    };
};
static_assert(sizeof(E_ActorAction::Type) == 1, "E_ActorAction::Type size mismatch");

}  // namespace wh::entitymodule
