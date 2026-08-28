#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

enum class E_CameraCommandType : std::uint8_t {
    Undefined = 0,
    Master    = 1,
    Medium    = 2,
    CloseShot = 3,
    CloseUp   = 4,
    Custom    = 5,
};
static_assert(sizeof(E_CameraCommandType) == 1, "E_CameraCommandType size mismatch");

}  // namespace wh::dialogmodule::data
