#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::framework {

struct E_ContentFilter {
    enum Type : std::uint8_t {
        Nudity        = 0,
        Sex           = 1,
        Homosexuality = 2,
        Gore          = 3,
        Gamescom      = 4,
    };
};
static_assert(sizeof(E_ContentFilter::Type) == 1, "E_ContentFilter::Type size mismatch");

}  // namespace wh::framework
