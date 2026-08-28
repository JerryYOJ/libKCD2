#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::guimodule {

struct E_FaderState {
    enum Type : std::uint8_t {
        FadedIn   = 0,
        FadingOut = 1,
        FadedOut  = 2,
        FadingIn  = 3,
    };
};
static_assert(sizeof(E_FaderState::Type) == 1, "E_FaderState::Type size mismatch");

}  // namespace wh::guimodule
