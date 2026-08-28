#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_StanceCategory {
    enum Type : std::int32_t {
        undefined = 0,
        standing  = 1,
        lying     = 2,
        sitting   = 3,
        kneel     = 4,
        horse     = 5,
        crouch    = 6,
        cart      = 7,
    };
};
static_assert(sizeof(E_StanceCategory::Type) == 4, "E_StanceCategory::Type size mismatch");

}  // namespace wh::entitymodule
