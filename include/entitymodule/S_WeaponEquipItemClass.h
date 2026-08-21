#pragma once
#include <cstddef>
#include "S_EquippableItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_WeaponEquipItemClass -- KCD2 1.5.6. sizeof 0xE8.
// -----------------------------------------------
// E_ItemType::WeaponEquip (24). Vtable 0x183EB61A0. No own fields.
// In-place = Equippable ctor + vtable overwrite. Clone alloc 0xE8 (sub_182A1E9A4).

namespace wh::entitymodule {

class S_WeaponEquipItemClass : public S_EquippableItemClass {
public:
};
static_assert(sizeof(S_WeaponEquipItemClass) == 0xE8, "S_WeaponEquipItemClass must be 0xE8");

}  // namespace wh::entitymodule
