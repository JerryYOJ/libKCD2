#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_LoadingMovement {
    enum Type : std::uint8_t {
        Allow           = 0,
        AllowWhenCocked = 1,
        Disable         = 2,
    };
};
static_assert(sizeof(E_LoadingMovement::Type) == 1, "E_LoadingMovement::Type size mismatch");

}  // namespace wh::entitymodule
