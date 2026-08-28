#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_ItemDeliveryMode {
    enum Type : std::uint8_t {
        CanMore     = 0,
        CanLess     = 1,
        Exactly     = 2,
        Any         = 3,
        AnyInfinite = 4,
    };
};
static_assert(sizeof(E_ItemDeliveryMode::Type) == 1, "E_ItemDeliveryMode::Type size mismatch");

}  // namespace wh::entitymodule
