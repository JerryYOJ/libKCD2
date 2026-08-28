#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::game {

struct E_PhotomodeParameterSourceType {
    enum Type : std::uint8_t {
        Same  = 0,
        Int   = 1,
        Float = 2,
        Vec3  = 3,
    };
};
static_assert(sizeof(E_PhotomodeParameterSourceType::Type) == 1, "E_PhotomodeParameterSourceType::Type size mismatch");

}  // namespace wh::game
