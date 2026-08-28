#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_OutfittingMode {
    enum Type : std::uint8_t {
        Unequip    = 0,
        Equip      = 1,
        ForceEquip = 2,
    };
};
static_assert(sizeof(E_OutfittingMode::Type) == 1, "E_OutfittingMode::Type size mismatch");

}  // namespace wh::entitymodule
