#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::conceptmodule {

enum class E_PortVisibility : std::int32_t {
    Interface = 0,
    Internal  = 1,
    External  = 2,
};
static_assert(sizeof(E_PortVisibility) == 4, "E_PortVisibility size mismatch");

}  // namespace wh::conceptmodule
