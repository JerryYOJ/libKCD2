#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_MatchContext {
    enum Type : std::uint8_t {
        Basic    = 0,
        Advanced = 1,
    };
};
static_assert(sizeof(E_MatchContext::Type) == 1, "E_MatchContext::Type size mismatch");

}  // namespace wh::entitymodule
