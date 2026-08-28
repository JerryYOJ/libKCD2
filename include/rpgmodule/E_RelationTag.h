#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

enum class E_RelationTag : std::int32_t {
    Schadenfreude = 0,
};
static_assert(sizeof(E_RelationTag) == 4, "E_RelationTag size mismatch");

}  // namespace wh::rpgmodule
