#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::conceptmodule {

struct E_CallbackSceneState {
    enum Type : std::uint8_t {
        Finish    = 0,
        Interrupt = 1,
    };
};
static_assert(sizeof(E_CallbackSceneState::Type) == 1, "E_CallbackSceneState::Type size mismatch");

}  // namespace wh::conceptmodule
