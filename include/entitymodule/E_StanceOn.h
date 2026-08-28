#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_StanceOn {
    enum Type : std::uint8_t {
        none   = 0,
        ground = 1,
        bench  = 2,
        table  = 3,
        bed    = 4,
    };
};
static_assert(sizeof(E_StanceOn::Type) == 1, "E_StanceOn::Type size mismatch");

}  // namespace wh::entitymodule
