#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::conceptmodule {

enum class E_HintType : std::int32_t {
    Performance      = 0,
    Usability        = 1,
    UsabilityWarning = 2,
    Resource         = 3,
    DeadLock         = 4,
    SubSystem        = 5,
};
static_assert(sizeof(E_HintType) == 4, "E_HintType size mismatch");

}  // namespace wh::conceptmodule
