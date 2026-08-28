#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_MovementDirection {
    enum Type : std::uint8_t {
        none     = 0,
        forward  = 1,
        backward = 2,
    };
};
static_assert(sizeof(E_MovementDirection::Type) == 1, "E_MovementDirection::Type size mismatch");

}  // namespace wh::entitymodule
