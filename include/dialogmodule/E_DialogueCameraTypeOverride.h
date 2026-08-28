#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule {

struct E_DialogueCameraTypeOverride {
    enum Type : std::uint8_t {
        NoOverride = 0,
        Medium     = 1,
        CloseShot  = 2,
        Closeup    = 3,
        Master     = 4,
    };
};
static_assert(sizeof(E_DialogueCameraTypeOverride::Type) == 1, "E_DialogueCameraTypeOverride::Type size mismatch");

}  // namespace wh::dialogmodule
