#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::framework {

struct E_TimeType {
    enum Type : std::int32_t {
        WorldTime = 0,
        GameTime  = 1,
    };
};
static_assert(sizeof(E_TimeType::Type) == 4, "E_TimeType::Type size mismatch");

}  // namespace wh::framework
