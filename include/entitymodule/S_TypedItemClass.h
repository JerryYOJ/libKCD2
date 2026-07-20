#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::S_TypedItemClass -- the typed-mixin secondary base of every CONCRETE item
// class (KCD2 WHGame.dll 1.5.6).  sizeof 0x10.
// -----------------------------------------------
// RTTI .?AUS_TypedItemClass@entitymodule@wh@@ (appears in every leaf's RTTR shared_ptr
// type-converter set).  Brought in once per concrete branch by S_ItemClassWrapper<D, P, TypeId>
// and REUSED by concrete-from-concrete leaves: S_CraftingMaterialItemClass places it at +0xC8
// and S_HerbItemClass keeps that one (herb's own fields start at +0xD8).  Each leaf overrides
// the 4-slot secondary vtable with adjustor thunks back into the main object (herb vtable
// ??_7S_HerbItemClass@..._0 0x183A4D840: all four = `thunk(this - 0xC8)`).
// Ctor default = {vptr, -1, -1} (dossier analysis/item_data/s_itemdata_re.md leaf ctors).

namespace wh::entitymodule {

struct S_TypedItemClass {
    virtual void unk0() = 0;   // [0] herb thunk -> 0x182A44084 (dtor region)
    virtual void unk1() = 0;   // [1] herb thunk -> 0x18161D250 [role UNVERIFIED]
    virtual void unk2() = 0;   // [2] herb thunk -> 0x1805F5DA0 (`return this` main object -- GetItemClass candidate)
    virtual void unk3() = 0;   // [3] herb thunk -> 0x18096F850 [role UNVERIFIED]

    int32_t m_unk08 = -1;      // +0x08  ctor -1; Type=/SubType= column binding UNVERIFIED
    int32_t m_unk0C = -1;      // +0x0C  ctor -1
};
static_assert(sizeof(S_TypedItemClass) == 0x10, "S_TypedItemClass must be 0x10");

}  // namespace wh::entitymodule
