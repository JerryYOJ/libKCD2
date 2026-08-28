#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::NPCState {

struct E_UnknownWeaponSetMode {
    enum Type : std::uint8_t {
        NotSupported                  = 0,
        AllowItemsFromChangeEquipment = 1,
        AllowItemsFromInventory       = 2,
    };
};
static_assert(sizeof(E_UnknownWeaponSetMode::Type) == 1, "E_UnknownWeaponSetMode::Type size mismatch");

}  // namespace wh::xgenaimodule::NPCState
