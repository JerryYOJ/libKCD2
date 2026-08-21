#pragma once
#include <cstddef>
#include <cstdint>
#include "S_ConsumableItemClass.h"
#include "S_TypedItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_OintmentItemClass -- KCD2 1.5.6. sizeof 0xF8.
// -----------------------------------------------
// E_ItemType::Ointment (13). Vtable 0x183BCCD88, ctor sub_1815E8D90,
// Clone helper alloc 0xF8 (sub_182A428C0). Mixin at +0xE0. Efficiency @+0xF0.

namespace wh::entitymodule {

class S_OintmentItemClass
    : public S_ConsumableItemClass               // +0x00 .. 0xE0
    , public S_TypedItemClass {                  // +0xE0 .. 0xF0
public:
    float m_efficiency;                          // +0xF0  RTTR "Efficiency"  ctor 1.0f
    std::uint8_t _padF4[4];                      // +0xF4
};
static_assert(sizeof(S_OintmentItemClass) == 0xF8, "S_OintmentItemClass must be 0xF8");
static_assert(offsetof(S_OintmentItemClass, m_efficiency) == 0xF0);

}  // namespace wh::entitymodule
