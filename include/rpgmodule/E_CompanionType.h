#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_CompanionType {
    enum Type : std::uint8_t {
        Horse = 0,
        Dog   = 1,
    };
};
static_assert(sizeof(E_CompanionType::Type) == 1, "E_CompanionType::Type size mismatch");

}  // namespace wh::rpgmodule
