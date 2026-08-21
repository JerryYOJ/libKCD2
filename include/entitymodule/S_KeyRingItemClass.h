#pragma once
#include <cstddef>
#include "S_DivisibleItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_KeyRingItemClass -- KCD2 1.5.6. sizeof 0xC8.
// -----------------------------------------------
// E_ItemType::KeyRing (18). Vtable 0x183C33EA8. No own fields, no mixin.
// Heap factory sub_18188B270, Clone alloc 0xC8 (sub_182A1E744).

namespace wh::entitymodule {

class S_KeyRingItemClass : public S_DivisibleItemClass {
public:
};
static_assert(sizeof(S_KeyRingItemClass) == 0xC8, "S_KeyRingItemClass must be 0xC8");

}  // namespace wh::entitymodule
