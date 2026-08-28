#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::game {

struct E_PhotomodeHandlerVec3Component {
    enum Type : std::uint8_t {
        X = 0,
        Y = 1,
        Z = 2,
        H = 3,
        S = 4,
        V = 5,
    };
};
static_assert(sizeof(E_PhotomodeHandlerVec3Component::Type) == 1, "E_PhotomodeHandlerVec3Component::Type size mismatch");

}  // namespace wh::game
