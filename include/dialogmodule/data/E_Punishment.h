#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

struct E_Punishment {
    enum Type : std::uint8_t {
        None      = 0,
        Pillory   = 1,
        Beating   = 2,
        Branding  = 3,
        Execution = 4,
    };
};
static_assert(sizeof(E_Punishment::Type) == 1, "E_Punishment::Type size mismatch");

}  // namespace wh::dialogmodule::data
