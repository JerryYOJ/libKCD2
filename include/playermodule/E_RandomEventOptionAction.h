#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_RandomEventOptionAction {
    enum Type : std::uint8_t {
        Continue = 0,
        Stop     = 1,
    };
};
static_assert(sizeof(E_RandomEventOptionAction::Type) == 1, "E_RandomEventOptionAction::Type size mismatch");

}  // namespace wh::playermodule
