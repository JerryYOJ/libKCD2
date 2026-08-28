#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::conceptmodule {

enum class E_TraceLevel : std::int32_t {
    Fatal   = 0,
    Error   = 1,
    Warning = 2,
    Info    = 3,
    Detail  = 4,
    Debug   = 5,
    Brutus  = 6,
};
static_assert(sizeof(E_TraceLevel) == 4, "E_TraceLevel size mismatch");

}  // namespace wh::conceptmodule
