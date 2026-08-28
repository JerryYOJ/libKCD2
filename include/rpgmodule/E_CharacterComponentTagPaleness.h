#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_CharacterComponentTagPaleness {
    enum Type : std::uint8_t {
        Pale      = 0,
        Ordinary  = 1,
        Suntanned = 2,
        Cuman     = 3,
        Roma      = 4,
    };
};
static_assert(sizeof(E_CharacterComponentTagPaleness::Type) == 1, "E_CharacterComponentTagPaleness::Type size mismatch");

}  // namespace wh::rpgmodule
