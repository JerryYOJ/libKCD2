#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::scheduler {

struct E_Weather {
    enum Type : std::uint8_t {
        Default = 0,
        Rain    = 1,
        Sun     = 2,
    };
};
static_assert(sizeof(E_Weather::Type) == 1, "E_Weather::Type size mismatch");

}  // namespace wh::xgenaimodule::scheduler
