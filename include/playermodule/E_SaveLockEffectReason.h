#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_SaveLockEffectReason {
    enum Type : std::uint8_t {
        Script   = 0,
        Minigame = 1,
        Combat   = 2,
    };
};
static_assert(sizeof(E_SaveLockEffectReason::Type) == 1, "E_SaveLockEffectReason::Type size mismatch");

}  // namespace wh::playermodule
