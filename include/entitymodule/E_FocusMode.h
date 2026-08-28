#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_FocusMode {
    enum Type : std::uint8_t {
        ViewRotationOnly            = 0,
        AlignEntityRotationWithView = 1,
        EntityRotationAfterDelay    = 2,
    };
};
static_assert(sizeof(E_FocusMode::Type) == 1, "E_FocusMode::Type size mismatch");

}  // namespace wh::entitymodule
