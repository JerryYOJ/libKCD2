#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_StanceSide {
    enum Type : std::int32_t {
        none  = 0,
        left  = 1,
        right = 2,
    };
};
static_assert(sizeof(E_StanceSide::Type) == 4, "E_StanceSide::Type size mismatch");

}  // namespace wh::entitymodule
