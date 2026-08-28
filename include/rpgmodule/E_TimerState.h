#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_TimerState {
    enum Type : std::uint8_t {
        Stopped  = 0,
        Running  = 1,
        Finished = 2,
    };
};
static_assert(sizeof(E_TimerState::Type) == 1, "E_TimerState::Type size mismatch");

}  // namespace wh::rpgmodule
