#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_SoulCrimeRole {
    enum Type : std::int32_t {
        none     = 0,
        civilian = 1,
        soldier  = 2,
        renegade = 3,
        monk     = 4,
        circator = 5,
    };
};
static_assert(sizeof(E_SoulCrimeRole::Type) == 4, "E_SoulCrimeRole::Type size mismatch");

}  // namespace wh::rpgmodule
