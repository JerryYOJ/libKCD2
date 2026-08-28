#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_AmmoLength {
    enum Type : std::uint8_t {
        Short  = 0,
        Medium = 1,
        Long   = 2,
    };
};
static_assert(sizeof(E_AmmoLength::Type) == 1, "E_AmmoLength::Type size mismatch");

}  // namespace wh::entitymodule
