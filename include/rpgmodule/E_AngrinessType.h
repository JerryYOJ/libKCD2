#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_AngrinessType {
    enum Type : std::uint8_t {
        Violence = 0,
        Material = 1,
    };
};
static_assert(sizeof(E_AngrinessType::Type) == 1, "E_AngrinessType::Type size mismatch");

}  // namespace wh::rpgmodule
