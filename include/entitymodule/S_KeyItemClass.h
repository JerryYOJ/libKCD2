#pragma once
#include <cstddef>
#include "S_PlayerItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_KeyItemClass -- KCD2 1.5.6. sizeof 0xB0.
// -----------------------------------------------
// E_ItemType::Key (17). Vtable 0x183C20498. No own fields, no mixin.
// Heap factory sub_1817E7138, Clone alloc 0xB0 (sub_182A45800).

namespace wh::entitymodule {

class S_KeyItemClass : public S_PlayerItemClass {
public:
};
static_assert(sizeof(S_KeyItemClass) == 0xB0, "S_KeyItemClass must be 0xB0");

}  // namespace wh::entitymodule
