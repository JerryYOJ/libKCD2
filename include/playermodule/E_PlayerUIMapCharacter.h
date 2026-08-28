#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_PlayerUIMapCharacter {
    enum Type : std::uint8_t {
        Henry  = 0,
        Bohuta = 1,
    };
};
static_assert(sizeof(E_PlayerUIMapCharacter::Type) == 1, "E_PlayerUIMapCharacter::Type size mismatch");

}  // namespace wh::playermodule
