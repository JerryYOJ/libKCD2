#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::game {

struct E_PhotomodeParameterType {
    enum Type : std::uint8_t {
        None            = 0,
        CVar            = 1,
        PostEffect      = 2,
        EngineParameter = 3,
        Custom          = 4,
    };
};
static_assert(sizeof(E_PhotomodeParameterType::Type) == 1, "E_PhotomodeParameterType::Type size mismatch");

}  // namespace wh::game
