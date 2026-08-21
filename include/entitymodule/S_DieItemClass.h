#pragma once
#include <cstddef>
#include <cstdint>
#include "S_DivisibleItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_DieItemClass -- KCD2 1.5.6. sizeof 0xF8.
// -----------------------------------------------
// E_ItemType::Die (15). Vtable 0x183BB5828, ctor sub_181559DC0,
// Clone helper alloc 0xF8. No mixin. RTTR registrar sub_180133F20.

namespace wh::entitymodule {

class S_DieItemClass : public S_DivisibleItemClass {
public:
    float         m_sideWeights[6];              // +0xC8  RTTR "SideWeights"  ctor 0
    std::int32_t  m_sideValues[6];               // +0xE0  RTTR "SideValues"  ctor {1,2,3,4,5,6}
};
static_assert(sizeof(S_DieItemClass) == 0xF8, "S_DieItemClass must be 0xF8");
static_assert(offsetof(S_DieItemClass, m_sideWeights) == 0xC8);
static_assert(offsetof(S_DieItemClass, m_sideValues) == 0xE0);

}  // namespace wh::entitymodule
