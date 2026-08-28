#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_FTDisableRandomEvents {
    enum Type : std::uint8_t {
        None          = 0,
        NonGuaranteed = 1,
        Generic       = 2,
        All           = 3,
    };
};
static_assert(sizeof(E_FTDisableRandomEvents::Type) == 1, "E_FTDisableRandomEvents::Type size mismatch");

}  // namespace wh::playermodule
