#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_CharacterComponentTagAge {
    enum Type : std::uint8_t {
        NotSet     = 0,
        YoungAdult = 1,
        MiddleAged = 2,
        Old        = 3,
        Ancient    = 4,
    };
};
static_assert(sizeof(E_CharacterComponentTagAge::Type) == 1, "E_CharacterComponentTagAge::Type size mismatch");

}  // namespace wh::rpgmodule
