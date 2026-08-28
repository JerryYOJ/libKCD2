#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_LadderState {
    enum Type : std::uint8_t {
        none     = 0,
        getOn    = 1,
        getOff   = 2,
        climbing = 3,
    };
};
static_assert(sizeof(E_LadderState::Type) == 1, "E_LadderState::Type size mismatch");

}  // namespace wh::entitymodule
