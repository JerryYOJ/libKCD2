#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_CartState {
    enum Type : std::uint8_t {
        idle              = 0,
        blocked           = 1,
        waitingForCaravan = 2,
        needConfirmation  = 3,
        moving            = 4,
        stopping          = 5,
    };
};
static_assert(sizeof(E_CartState::Type) == 1, "E_CartState::Type size mismatch");

}  // namespace wh::entitymodule
