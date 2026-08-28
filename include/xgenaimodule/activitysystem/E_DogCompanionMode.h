#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::activitysystem {

struct E_DogCompanionMode {
    enum Type : std::uint8_t {
        Wait       = 0,
        Follow     = 1,
        Free       = 2,
        Aggressive = 3,
        Search     = 4,
        Hunt       = 5,
        Guard      = 6,
        Ambush     = 7,
    };
};
static_assert(sizeof(E_DogCompanionMode::Type) == 1, "E_DogCompanionMode::Type size mismatch");

}  // namespace wh::xgenaimodule::activitysystem
