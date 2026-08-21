#pragma once
#include <cstddef>
#include "S_PlayerItemClass.h"
#include "S_TypedItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_DiceBadgeItemClass -- KCD2 1.5.6. sizeof 0xC0.
// -----------------------------------------------
// E_ItemType::DiceBadge (7). Vtable 0x183BC2270, ctor sub_18159D5B4,
// Clone helper alloc 0xC0. Mixin at +0xB0. No own fields past the mixin.

namespace wh::entitymodule {

class S_DiceBadgeItemClass
    : public S_PlayerItemClass                   // +0x00 .. 0xB0
    , public S_TypedItemClass {                  // +0xB0 .. 0xC0
public:
};
static_assert(sizeof(S_DiceBadgeItemClass) == 0xC0, "S_DiceBadgeItemClass must be 0xC0");

}  // namespace wh::entitymodule
