#pragma once
#include <cstddef>
#include <cstdint>
#include "S_PickableItemClass.h"
#include "S_TypedItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_NPCToolItemClass -- KCD2 1.5.6. sizeof 0xA8.
// -----------------------------------------------
// E_ItemType::NPCTool (12). Vtable 0x183B6D678, ctor sub_181387034,
// Clone alloc 0xA8. Mixin at +0x90. RTTR registrar sub_18012F6A0.

namespace wh::entitymodule {

class S_NPCToolItemClass
    : public S_PickableItemClass                 // +0x00 .. 0x90
    , public S_TypedItemClass {                  // +0x90 .. 0xA0
public:
    std::int32_t m_manipulationType;             // +0xA0  RTTR "ManipulationType"  ctor 1
    bool         m_allowUnstream;                // +0xA4  RTTR "AllowUnstream"
    std::uint8_t _padA5[3];                      // +0xA5
};
static_assert(sizeof(S_NPCToolItemClass) == 0xA8, "S_NPCToolItemClass must be 0xA8");
static_assert(offsetof(S_NPCToolItemClass, m_manipulationType) == 0xA0);

}  // namespace wh::entitymodule
