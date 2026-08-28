#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule::storm {

enum class E_TaskClass : std::uint16_t {
    roles       = 1,
    abilities   = 2,
    schedules   = 4,
    names       = 8,
    reputations = 16,
    hobbies     = 32,
    contexts    = 64,
    equipment   = 128,
    appearance  = 256,
    characters  = 512,
};
static_assert(sizeof(E_TaskClass) == 2, "E_TaskClass size mismatch");

}  // namespace wh::rpgmodule::storm
