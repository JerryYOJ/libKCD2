#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_StanceBy {
    enum Type : std::uint8_t {
        none    = 0,
        table   = 1,
        chest   = 2,
        tent    = 3,
        shelter = 4,
    };
};
static_assert(sizeof(E_StanceBy::Type) == 1, "E_StanceBy::Type size mismatch");

}  // namespace wh::entitymodule
