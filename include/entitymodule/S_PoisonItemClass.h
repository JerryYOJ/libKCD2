#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "S_ConsumableItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_PoisonItemClass -- KCD2 1.5.6. sizeof 0xF8.
// -----------------------------------------------
// E_ItemType::Poison (14). Vtable 0x183A978D8, ctor sub_180D29758,
// Clone helper alloc 0xF8. No S_TypedItemClass mixin.

namespace wh::entitymodule {

class S_PoisonItemClass : public S_ConsumableItemClass {
public:
    std::uint32_t m_weaponChargeCount;           // +0xE0  RTTR "WeaponChargeCount"  ctor 1
    std::uint32_t m_ammoApplyCount;              // +0xE4  RTTR "AmmoApplyCount"  ctor 1
    CryGUID       m_weaponBuffDefinitionId;      // +0xE8  RTTR "WeaponBuffDefinitionId"
};
static_assert(sizeof(S_PoisonItemClass) == 0xF8, "S_PoisonItemClass must be 0xF8");
static_assert(offsetof(S_PoisonItemClass, m_weaponChargeCount) == 0xE0);

}  // namespace wh::entitymodule
