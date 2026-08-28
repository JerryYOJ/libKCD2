#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_VoiceCategory {
    enum Type : std::uint8_t {
        generic   = 0,
        cuman     = 1,
        german    = 2,
        romani    = 3,
        jew       = 4,
        christian = 5,
    };
};
static_assert(sizeof(E_VoiceCategory::Type) == 1, "E_VoiceCategory::Type size mismatch");

}  // namespace wh::rpgmodule
