#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

enum class E_ItemCategory : std::int32_t {
    Misc               = 0,
    MeleeWeapon        = 1,
    MissileWeapon      = 2,
    Ammo               = 3,
    Armor              = 4,
    Food               = 5,
    Money              = 6,
    Document           = 8,
    CraftingMaterial   = 9,
    Herb               = 10,
    AlchemyBase        = 11,
    NPCTool            = 12,
    Ointment           = 13,
    Poison             = 14,
    Die                = 15,
    DiceBadge          = 7,
    Helmet             = 16,
    Key                = 17,
    KeyRing            = 18,
    PlayerItem         = 25,
    EquippableItem     = 26,
    Weapon             = 27,
    ConsumableItem     = 28,
    QuickSlotContainer = 19,
    Hood               = 29,
    Invalid            = -1,
};
static_assert(sizeof(E_ItemCategory) == 4, "E_ItemCategory size mismatch");

}  // namespace wh::entitymodule
