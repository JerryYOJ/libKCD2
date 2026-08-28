#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::guimodule {

struct E_CutsceneProfileType {
    enum Type : std::int32_t {
        Default = 1,
        XBOX    = 2,
        PS5     = 4,
        Console = 6,
    };
};
static_assert(sizeof(E_CutsceneProfileType::Type) == 4, "E_CutsceneProfileType::Type size mismatch");

}  // namespace wh::guimodule
