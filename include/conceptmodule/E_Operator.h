#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::conceptmodule {

enum class E_Operator : std::int32_t {
    Equals        = 0,
    NotEquals     = 1,
    Greater       = 2,
    GreaterEquals = 3,
    Less          = 4,
    LessEquals    = 5,
};
static_assert(sizeof(E_Operator) == 4, "E_Operator size mismatch");

}  // namespace wh::conceptmodule
