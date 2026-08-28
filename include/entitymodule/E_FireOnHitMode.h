#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_FireOnHitMode {
    enum Type : std::uint8_t {
        None         = 0,
        Fire         = 1,
        MisfireIfLit = 2,
    };
};
static_assert(sizeof(E_FireOnHitMode::Type) == 1, "E_FireOnHitMode::Type size mismatch");

}  // namespace wh::entitymodule
