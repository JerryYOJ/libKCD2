#pragma once
#include <cstdint>
#include <vector>
#include "rttr/rttr_enable.h"

// -----------------------------------------------
// wh::entitymodule::I_ItemDescriptor -- item match/filter interface (KCD2 1.5.6, kd7u).
// sizeof 0x08 (vtable only).
// -----------------------------------------------
// RTTI .?AVI_ItemDescriptor@entitymodule@wh@@ (RTTR "ItemDescriptor", sizeof 8; registrar
// 0x181100510 binds names GetMatchingItems / FullyMatchesItems / InputItems). Never
// instantiated most-derived (no own COL/vtable); the 10-slot shape is proven by the
// C_ItemPropertyDescriptor (0x183A3D590) / C_ItemClassDescriptor (0x183A3D5E8) vtables.
// Chain: I_ItemDescriptor -> C_HomogenousItemDescriptor -> C_ItemPropertyDescriptor ->
// C_ItemClassDescriptor (all mdisp 0, no MI/VI). Slot->RTTR-name pairing for [1] is
// signature-matched; FullyMatchesItems' exact slot is UNPROVEN (vf[3] is a per-item
// predicate, not the registered vector signature).

namespace wh::entitymodule {

class C_Item;

class I_ItemDescriptor {
public:
    virtual ~I_ItemDescriptor() = default;                                        // [0]
    // Collect up to GetAmount() matches from `items` (-1 = unlimited); per-item test = vf[3].
    virtual std::vector<C_Item*> GetMatchingItems(const std::vector<C_Item*>& items) const = 0; // [1] 0x18096EF4C (RTTR name; sig-matched)
    virtual void unk2() = 0;                                                      // [2] 0x18096E81C match/partial/overflow partition; sig UNVERIFIED
    virtual bool MatchesItem(C_Item* item, std::uint32_t flags) const = 0;        // [3] 0x18096F1A4 = (vf[4]==0); name reconstructed
    virtual std::uint32_t GetMatchFailReason(C_Item* item, std::uint32_t flags) const = 0; // [4] 0 = match; reason codes (9 quality, 0xA condition, ...)
    virtual std::int32_t unk5() const = 0;                                        // [5] 0x1804C88CC tail-calls [9]; role UNVERIFIED
    RTTR_ENABLE()  // [6..8]: get_type / get_ptr / get_derived_info
    virtual std::int32_t GetAmount() const = 0;                                   // [9] 0x181A72970 -> +0x08 on Property; -1 = unlimited
};

}  // namespace wh::entitymodule
