#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

enum class E_CommandTimingMode : std::uint8_t {
    Auto     = 0,
    Relative = 1,
    Absolute = 2,
};
static_assert(sizeof(E_CommandTimingMode) == 1, "E_CommandTimingMode size mismatch");

}  // namespace wh::dialogmodule::data
