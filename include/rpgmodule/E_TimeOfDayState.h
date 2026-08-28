#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_TimeOfDayState {
    enum Type : std::uint8_t {
        Finished = 0,
        Running  = 1,
    };
};
static_assert(sizeof(E_TimeOfDayState::Type) == 1, "E_TimeOfDayState::Type size mismatch");

}  // namespace wh::rpgmodule
