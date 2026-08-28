#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

struct E_CharacterCreation {
    enum Type : std::uint8_t {
        None         = 0,
        Warrior      = 1,
        Diplomat     = 2,
        Scout        = 3,
        Strength     = 4,
        Agility      = 5,
        Vitality     = 6,
        Speech       = 7,
        Houndmaster  = 8,
        Stealth      = 9,
        Survival     = 10,
        Scholarship  = 11,
        Swords       = 12,
        HeavyWeapons = 13,
        Unarmed      = 14,
        Marksman     = 15,
    };
};
static_assert(sizeof(E_CharacterCreation::Type) == 1, "E_CharacterCreation::Type size mismatch");

}  // namespace wh::dialogmodule::data
