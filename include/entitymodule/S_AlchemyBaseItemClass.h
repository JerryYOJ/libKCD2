#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_ItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_AlchemyBaseItemClass -- water/wine/spirit (KCD2 1.5.6).
// sizeof 0x40.  E_ItemType::AlchemyBase (11).
// -----------------------------------------------
// Parent is S_ItemClass (NOT Pickable). Vtable 0x183C0DE90, ctor sub_18175F528,
// Clone helper sub_182A1AD3C. No mixin.

namespace wh::entitymodule {

class S_AlchemyBaseItemClass : public S_ItemClass {
public:
    CryStringT<char> m_uiName;                   // +0x38  RTTR "UIName"
};
static_assert(sizeof(S_AlchemyBaseItemClass) == 0x40, "S_AlchemyBaseItemClass must be 0x40");
static_assert(offsetof(S_AlchemyBaseItemClass, m_uiName) == 0x38);

}  // namespace wh::entitymodule
