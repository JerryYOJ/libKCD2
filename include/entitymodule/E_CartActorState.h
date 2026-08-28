#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_CartActorState {
    enum Type : std::uint8_t {
        none            = 0,
        waitingForMount = 1,
        mounting        = 2,
        dismounting     = 3,
        fastDismounting = 4,
        sitting         = 5,
        riensGo         = 6,
        riensStop       = 7,
    };
};
static_assert(sizeof(E_CartActorState::Type) == 1, "E_CartActorState::Type size mismatch");

}  // namespace wh::entitymodule
