#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule {

struct E_HandType {
    enum Type : std::int32_t {
        Right = 0,
        Left  = 1,
    };
};
static_assert(sizeof(E_HandType::Type) == 4, "E_HandType::Type size mismatch");

}  // namespace wh::xgenaimodule
