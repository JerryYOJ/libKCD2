#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::conceptmodule {

enum class E_ConstraintType : std::int32_t {
    None  = 0,
    Table = 1,
    Asset = 2,
};
static_assert(sizeof(E_ConstraintType) == 4, "E_ConstraintType size mismatch");

}  // namespace wh::conceptmodule
