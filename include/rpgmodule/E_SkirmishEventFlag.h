#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_SkirmishEventFlag {
    enum Type : std::uint8_t {
        BarkWaitForGuard = 0,
        BarkInstant      = 1,
        VisiblePort      = 2,
        DeletedPort      = 3,
    };
};
static_assert(sizeof(E_SkirmishEventFlag::Type) == 1, "E_SkirmishEventFlag::Type size mismatch");

}  // namespace wh::rpgmodule
