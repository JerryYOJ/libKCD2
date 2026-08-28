#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::conceptmodule::definition {

enum class E_TypeClass : std::int32_t {
    ValueType     = 0,
    ReferenceType = 1,
    Enumeration   = 2,
    Sequential    = 3,
    Associative   = 4,
    Trigger       = 5,
};
static_assert(sizeof(E_TypeClass) == 4, "E_TypeClass size mismatch");

}  // namespace wh::conceptmodule::definition
