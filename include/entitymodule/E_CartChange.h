#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_CartChange {
    enum Type : std::uint8_t {
        targetReached    = 0,
        targetNotReached = 1,
    };
};
static_assert(sizeof(E_CartChange::Type) == 1, "E_CartChange::Type size mismatch");

}  // namespace wh::entitymodule
