#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::questmodule {

enum class E_LogType : std::int32_t {
    None      = 0,
    Started   = 1,
    Updated   = 2,
    Completed = 3,
    Canceled  = 4,
};
static_assert(sizeof(E_LogType) == 4, "E_LogType size mismatch");

}  // namespace wh::questmodule
