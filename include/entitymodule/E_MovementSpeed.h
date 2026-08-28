#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_MovementSpeed {
    enum Type : std::uint8_t {
        idle   = 0,
        walk   = 1,
        run    = 2,
        sprint = 3,
        dash   = 4,
    };
};
static_assert(sizeof(E_MovementSpeed::Type) == 1, "E_MovementSpeed::Type size mismatch");

}  // namespace wh::entitymodule
