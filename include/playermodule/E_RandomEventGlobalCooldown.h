#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_RandomEventGlobalCooldown {
    enum Type : std::uint8_t {
        Default       = 0,
        City          = 1,
        GenericEvents = 2,
        Caravan       = 3,
        Fast          = 4,
    };
};
static_assert(sizeof(E_RandomEventGlobalCooldown::Type) == 1, "E_RandomEventGlobalCooldown::Type size mismatch");

}  // namespace wh::playermodule
