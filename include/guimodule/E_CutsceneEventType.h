#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::guimodule {

struct E_CutsceneEventType {
    enum Type : std::int32_t {
        SkipPoint  = 0,
        CustomText = 1,
        Subtitle   = 2,
    };
};
static_assert(sizeof(E_CutsceneEventType::Type) == 4, "E_CutsceneEventType::Type size mismatch");

}  // namespace wh::guimodule
