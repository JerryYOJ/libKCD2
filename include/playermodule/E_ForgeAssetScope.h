#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_ForgeAssetScope {
    enum Type : std::uint8_t {
        house = 0,
        room  = 1,
        yard  = 2,
    };
};
static_assert(sizeof(E_ForgeAssetScope::Type) == 1, "E_ForgeAssetScope::Type size mismatch");

}  // namespace wh::playermodule
