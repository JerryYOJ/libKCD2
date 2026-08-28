#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_CartMoveBlocker {
    enum Type : std::uint8_t {
        noDriver = 0,
        event    = 1,
        obstacle = 2,
        stash    = 3,
        player   = 4,
    };
};
static_assert(sizeof(E_CartMoveBlocker::Type) == 1, "E_CartMoveBlocker::Type size mismatch");

}  // namespace wh::entitymodule
