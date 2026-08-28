#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::conceptmodule {

enum class E_NodeUpdatePriority : std::int32_t {
    Normal       = 0,
    AutoExecuted = 1,
};
static_assert(sizeof(E_NodeUpdatePriority) == 4, "E_NodeUpdatePriority size mismatch");

}  // namespace wh::conceptmodule
