#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_ForgeAssetDefault {
    enum Type : std::uint8_t {
        notDefault = 0,
        rubble     = 1,
        empty      = 2,
    };
};
static_assert(sizeof(E_ForgeAssetDefault::Type) == 1, "E_ForgeAssetDefault::Type size mismatch");

}  // namespace wh::playermodule
