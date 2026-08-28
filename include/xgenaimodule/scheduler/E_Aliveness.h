#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::scheduler {

struct E_Aliveness {
    enum Type : std::uint8_t {
        Alive              = 0,
        Dead               = 1,
        Unconscious        = 2,
        DeadOrUnconscious  = 3,
        AliveOrUnconscious = 4,
        DeadOrAlive        = 5,
        Any                = 6,
    };
};
static_assert(sizeof(E_Aliveness::Type) == 1, "E_Aliveness::Type size mismatch");

}  // namespace wh::xgenaimodule::scheduler
