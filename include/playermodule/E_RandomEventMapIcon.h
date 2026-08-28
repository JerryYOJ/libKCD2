#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_RandomEventMapIcon {
    enum Type : std::uint8_t {
        None      = 0,
        Combat    = 1,
        Wanderer  = 2,
        Encounter = 3,
        Camp      = 4,
        City      = 5,
        Quest     = 6,
    };
};
static_assert(sizeof(E_RandomEventMapIcon::Type) == 1, "E_RandomEventMapIcon::Type size mismatch");

}  // namespace wh::playermodule
