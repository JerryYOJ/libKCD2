#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_CartHorseSlot {
    enum Type : std::uint8_t {
        left  = 0,
        right = 1,
    };
};
static_assert(sizeof(E_CartHorseSlot::Type) == 1, "E_CartHorseSlot::Type size mismatch");

}  // namespace wh::entitymodule
