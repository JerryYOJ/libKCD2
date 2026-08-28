#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule {

enum class E_PerceptionClass : std::int32_t {
    Primary   = 0,
    Secondary = 1,
};
static_assert(sizeof(E_PerceptionClass) == 4, "E_PerceptionClass size mismatch");

}  // namespace wh::xgenaimodule
