#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::guimodule {

struct E_CustomTextLayout {
    enum Type : std::uint8_t {
        Center       = 0,
        CenterBottom = 1,
        TopRight     = 2,
        CenterBig    = 3,
    };
};
static_assert(sizeof(E_CustomTextLayout::Type) == 1, "E_CustomTextLayout::Type size mismatch");

}  // namespace wh::guimodule
