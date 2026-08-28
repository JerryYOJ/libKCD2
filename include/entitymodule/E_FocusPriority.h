#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_FocusPriority {
    enum Type : std::uint8_t {
        Normal = 0,
        High   = 1,
    };
};
static_assert(sizeof(E_FocusPriority::Type) == 1, "E_FocusPriority::Type size mismatch");

}  // namespace wh::entitymodule
