#pragma once
#include <cstdint>
#include <vector>

// -----------------------------------------------
// wh::entitymodule::I_ItemRuntimeData -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x58, ABSTRACT.
// -----------------------------------------------
// RTTI .?AVI_ItemRuntimeData@entitymodule@wh@@ (TD 0x184C38C80, COL 0x184141138)
// vtable 0x183A38F18 (24 slots; slot0/20/23 = _purecall => abstract; slot22 @vtable+0xB0 =
// sub_182A43FC0 = ref-counted scalar-deleting release, called vf(obj,1) to delete throughout)
// ctor sub_18046FBF0  dtor sub_180F19238.  Base sizeof from derived deltas: Consumable(0x68) -
// own 0x10 = 0x58; Key(0x60) - own 8 = 0x58.
//
// Per-item runtime state, lazily created and stored at C_Item+0x58 (m_pRuntimeData); back-ptr to
// the owning item @+0x48 (ctor a2; resolver sub_1804695B4 = "owner or global default"). Ctors read
// the item's static class definition via owner virtuals (idx6/idx24/idx26) to compute defaults.
//
// [FUNDAMENTAL vs KCD1] KCD1's concrete middle class C_ItemRuntimeData is GONE in KCD2 (bin_search
// for its RTTI string is empty) -- subclasses derive straight from this abstract base.
//
// Hierarchy: I_ItemRuntimeData <- {C_ConsumableRuntimeData, C_KeyRuntimeData,
// C_EquippableItemRuntimeData <- {C_ArmorRuntimeData, C_WeaponEquipRuntimeData <-
// {C_AmmoRuntimeData, C_WeaponRuntimeData <- {C_MeleeWeaponRuntimeData, C_MissileWeaponRuntimeData}}}}
// (all single-inheritance; every CHD BCD mdisp=0 -- no virtual bases, no this-adjust).

namespace wh::entitymodule {

class C_Item;

class I_ItemRuntimeData {
public:
    virtual ~I_ItemRuntimeData() = 0;   // vtable slot0 = _purecall in the binary (abstract);
                                        // real deletion goes through slot22 (ref-release, vf(obj,1))

    void*   m_sentinel08[2];    // +0x08  embedded 0x10 node the list ptrs point at (UNRESOLVED:
                                //        intrusive-list sentinel or signal-like sub-object)
    bool    m_flag18;           // +0x18  (=0)
    uint8_t _pad19[7];          // +0x19
    void*   m_pListNext;        // +0x20  init = &m_sentinel08 (empty intrusive list)
    void*   m_pListPrev;        // +0x28  init = &m_sentinel08
    std::vector<void*> m_vec30; // +0x30  REAL element stride 0x10 (element type unresolved; freed
                                //        via sub_180FF9998 in dtor)
    C_Item* m_pOwner;           // +0x48  owning item back-ptr (ctor a2)  VERIFIED
    void*   m_pCache50;         // +0x50  (=0; INFERRED cached provider ptr)
};
static_assert(sizeof(I_ItemRuntimeData) == 0x58, "I_ItemRuntimeData must be 0x58");
static_assert(offsetof(I_ItemRuntimeData, m_pOwner) == 0x48, "owner back-ptr at 0x48");

}  // namespace wh::entitymodule
