#pragma once
#include <cstddef>
#include "S_DivisibleItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_MoneyItemClass -- KCD2 1.5.6. sizeof 0xC8.
// -----------------------------------------------
// E_ItemType::Money (6). Vtable 0x183C33CA0. No own fields, no mixin.
// Heap factory sub_18188B100, Clone alloc 0xC8 (sub_182A1E7D4). No GetAs slot
// (inherits Divisible).

namespace wh::entitymodule {

class S_MoneyItemClass : public S_DivisibleItemClass {
public:
};
static_assert(sizeof(S_MoneyItemClass) == 0xC8, "S_MoneyItemClass must be 0xC8");

}  // namespace wh::entitymodule
