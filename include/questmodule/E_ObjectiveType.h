#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::questmodule {

enum class E_ObjectiveType : std::int32_t {
    Obligatory = 0,
    Optional   = 1,
};
static_assert(sizeof(E_ObjectiveType) == 4, "E_ObjectiveType size mismatch");

}  // namespace wh::questmodule
