#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::game {

struct E_PhotomodeHDRVisibility {
    enum Type : std::uint8_t {
        Always    = 0,
        OnlyInSDR = 1,
        OnlyInHDR = 2,
    };
};
static_assert(sizeof(E_PhotomodeHDRVisibility::Type) == 1, "E_PhotomodeHDRVisibility::Type size mismatch");

}  // namespace wh::game
