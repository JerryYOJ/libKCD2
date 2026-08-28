#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_CartSpeed {
    enum Type : std::uint8_t {
        normal = 0,
        fast   = 1,
    };
};
static_assert(sizeof(E_CartSpeed::Type) == 1, "E_CartSpeed::Type size mismatch");

}  // namespace wh::entitymodule
