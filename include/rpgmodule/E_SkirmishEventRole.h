#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_SkirmishEventRole {
    enum Type : std::uint8_t {
        Source          = 0,
        SourceCompanion = 1,
        SourceLeader    = 2,
        Target          = 3,
        TargetCompanion = 4,
        TargetLeader    = 5,
    };
};
static_assert(sizeof(E_SkirmishEventRole::Type) == 1, "E_SkirmishEventRole::Type size mismatch");

}  // namespace wh::rpgmodule
