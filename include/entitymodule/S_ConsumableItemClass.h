#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "S_DivisibleItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_ConsumableItemClass -- KCD2 1.5.6. sizeof 0xE0.
// -----------------------------------------------
// E_ItemType::Consumable (28). Vtable 0x183A4E188, ctor sub_1807532F0,
// copy-ctor sub_180D28B5C, Clone alloc 0xE0. No S_TypedItemClass mixin.

namespace wh::entitymodule {

class S_ConsumableItemClass : public S_DivisibleItemClass {
public:
    CryGUID          m_buffDefinitionId;         // +0xC8  RTTR "BuffDefinitionId"
    CryStringT<char> m_uiSound;                  // +0xD8  RTTR "UiSound"
};
static_assert(sizeof(S_ConsumableItemClass) == 0xE0, "S_ConsumableItemClass must be 0xE0");
static_assert(offsetof(S_ConsumableItemClass, m_buffDefinitionId) == 0xC8);

}  // namespace wh::entitymodule
