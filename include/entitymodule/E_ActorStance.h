#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

enum class E_ActorStance : std::int32_t {
    ACTORSTANCE_NULL          = -1,
    ACTORSTANCE_NORMAL        = 3,
    ACTORSTANCE_COMBAT        = 0,
    ACTORSTANCE_CROUCH        = 1,
    ACTORSTANCE_CARRYCORPSE   = 9,
    ACTORSTANCE_STONETHROWING = 2,
    ACTORSTANCE_INJURED       = 7,
    ACTORSTANCE_LAST          = 10,
};
static_assert(sizeof(E_ActorStance) == 4, "E_ActorStance size mismatch");

}  // namespace wh::entitymodule
