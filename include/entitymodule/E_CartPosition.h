#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_CartPosition {
    enum Type : std::uint8_t {
        driver     = 0,
        codriver   = 1,
        teamster   = 2,
        leftFront  = 3,
        rightFront = 4,
        leftBack   = 5,
        rightBack  = 6,
    };
};
static_assert(sizeof(E_CartPosition::Type) == 1, "E_CartPosition::Type size mismatch");

}  // namespace wh::entitymodule
