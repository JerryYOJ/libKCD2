#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh {

struct E_HLodType {
    enum Type : std::uint8_t {
        Unknown    = 0,
        Vegetation = 1,
        Cluster    = 2,
        Layer      = 3,
        Prefab     = 4,
        Interior   = 5,
    };
};
static_assert(sizeof(E_HLodType::Type) == 1, "E_HLodType::Type size mismatch");

}  // namespace wh
