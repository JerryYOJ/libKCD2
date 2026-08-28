#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_CharacterComponentTagRoughness {
    enum Type : std::uint8_t {
        Rough    = 0,
        Ordinary = 1,
        Posh     = 2,
        Cleric   = 3,
    };
};
static_assert(sizeof(E_CharacterComponentTagRoughness::Type) == 1, "E_CharacterComponentTagRoughness::Type size mismatch");

}  // namespace wh::rpgmodule
