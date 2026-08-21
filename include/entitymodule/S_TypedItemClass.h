#pragma once
#include <cstdint>
#include "rttr/rttr_enable.h"

// -----------------------------------------------
// wh::entitymodule::S_TypedItemClass -- the typed-mixin secondary base of every CONCRETE item
// class (KCD2 WHGame.dll 1.5.6).  sizeof 0x10.
// -----------------------------------------------
// RTTI .?AUS_TypedItemClass@entitymodule@wh@@. Optional secondary base -- NOT on every
// concrete leaf (Money/Die/KeyRing/Poison/Key have none). S_CraftingMaterialItemClass
// places it at +0xC8; S_HerbItemClass reuses that one. 4-slot mixin vtable; sizeof is
// copy-extent (no Clone-alloc). Ctor default = {vptr, Type=-1, SubType=-1}.

namespace wh::entitymodule {

struct S_TypedItemClass {
    inline static constexpr auto RTTI = Offsets::RTTI_S_TypedItemClass;
    virtual void unk0() = 0;   // [0] herb thunk -> 0x182A44084 (dtor region)
    RTTR_ENABLE()  // [1..3]: get_type 0x182A2446C, get_derived 0x182A23FAC (herb 2nd-vtable thunks -> herb's own trio)

    int32_t m_type = -1;       // +0x08  RTTR/XML Type  ctor -1
    int32_t m_subType = -1;    // +0x0C  RTTR/XML SubType  ctor -1
};
static_assert(sizeof(S_TypedItemClass) == 0x10, "S_TypedItemClass must be 0x10");

}  // namespace wh::entitymodule
