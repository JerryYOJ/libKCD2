#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

struct E_RepairShopType {
    enum Type : std::uint8_t {
        None        = 0,
        Armorer     = 1,
        Weaponsmith = 2,
        Tailor      = 3,
        Shoemaker   = 4,
        Gunsmith    = 5,
        Bowmaker    = 6,
        Blacksmith  = 7,
    };
};
static_assert(sizeof(E_RepairShopType::Type) == 1, "E_RepairShopType::Type size mismatch");

}  // namespace wh::dialogmodule::data
