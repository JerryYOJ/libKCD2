#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_Race {
    enum Type : std::int32_t {
        Invalid = -1,
        Human   = 0,
        Horse   = 1,
        Sheep   = 2,
        Hare    = 3,
        Pig     = 4,
        Hen     = 5,
        Dog     = 6,
        Cattle  = 7,
        RedDeer = 8,
        RoeDeer = 9,
    };
};
static_assert(sizeof(E_Race::Type) == 4, "E_Race::Type size mismatch");

}  // namespace wh::entitymodule
