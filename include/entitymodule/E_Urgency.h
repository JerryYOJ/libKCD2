#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_Urgency {
    enum Type : std::uint8_t {
        Default = 0,
        Slow    = 1,
        Fast    = 2,
        Instant = 3,
    };
};
static_assert(sizeof(E_Urgency::Type) == 1, "E_Urgency::Type size mismatch");

}  // namespace wh::entitymodule
