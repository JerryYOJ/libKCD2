#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_PresetOverrideMode {
    enum Type : std::uint8_t {
        Destroy                  = 0,
        Unequip                  = 1,
        KeepEquipped             = 2,
        ChangeToPlayerControlled = 3,
    };
};
static_assert(sizeof(E_PresetOverrideMode::Type) == 1, "E_PresetOverrideMode::Type size mismatch");

}  // namespace wh::rpgmodule
