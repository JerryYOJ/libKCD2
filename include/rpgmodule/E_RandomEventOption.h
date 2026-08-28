#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_RandomEventOption {
    enum Type : std::uint8_t {
        None      = 0,
        SureThing = 1,
        Evade     = 2,
        Ambush    = 3,
        Flee      = 4,
    };
};
static_assert(sizeof(E_RandomEventOption::Type) == 1, "E_RandomEventOption::Type size mismatch");

}  // namespace wh::rpgmodule
