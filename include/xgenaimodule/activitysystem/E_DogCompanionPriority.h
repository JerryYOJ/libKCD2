#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::activitysystem {

struct E_DogCompanionPriority {
    enum Type : std::int32_t {
        Impossible     = 0,
        Lowest         = 1,
        Doable         = 2,
        BestFun        = 3,
        Duty           = 4,
        Follow         = 5,
        Attack         = 6,
        ExecutingOrder = 7,
        Hit            = 8,
        GettingOrder   = 9,
        RunAway        = 10,
    };
};
static_assert(sizeof(E_DogCompanionPriority::Type) == 4, "E_DogCompanionPriority::Type size mismatch");

}  // namespace wh::xgenaimodule::activitysystem
