#pragma once
#include <cstdint>
#include <vector>
#include <unordered_map>
#include "E_QuickSlotSpec.h"
#include "I_ItemCollectionListener.h"
#include "../framework/WUID.h"

// -----------------------------------------------
// wh::entitymodule::C_EquipmentManager : I_ItemCollectionListener -- KCD2 1.5.6 (kd7u).  sizeof 0x130.
// -----------------------------------------------
// RTTI .?AVC_EquipmentManager@entitymodule@wh@@  primary vtable 0x183EB1708 (9 slots)  ctor sub_180A30D68
// Single inheritance: I_ItemCollectionListener (pure interface base, vtable @+0x00, no data).
// [MODERATE vs KCD1] m_handSlots grew 6 -> 8 entries. Equipment-change notification is a hand-rolled
// safe-iteration observer list (@+0x100), not a C_Signal.

namespace wh::entitymodule {

class C_Entity;
class C_Item;
class I_EquipmentObserver;

// One cached equipment-slot entry (0x10). Only the reflected EquipmentSlot id is proven; the other
// two fields are size-placeholders (co-registered E_QuickSlotSpec + a likely WUID) -- unverified.
struct S_EquipmentSlotIdWrapper {
    uint32_t equipmentSlot;   // +0x00  EquipmentSlotId (reflected "EquipmentSlot")
    E_QuickSlotSpec::Type quickSlotSpec;  // +0x04  (RTTR reg sub_180129670)
    uint64_t data08;          // +0x08  (likely wh::framework::WUID; unverified)
};

class C_EquipmentManager : public I_ItemCollectionListener {   // +0x00  (vtable only)
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_EquipmentManager;

    virtual void* EquipmentManagerUnk06(void* value);          // [6] sub_182A05414 [U role]
    virtual C_EquipmentManager* EquipmentManagerUnk07();       // [7] sub_1805F5DA0 returns this
    virtual void* EquipmentManagerUnk08(void* value);          // [8] sub_182A0529C [U role]

    C_Entity* m_owner;                                 // +0x08  owning entity/item-collection back-ptr (class tentative)
    std::vector<uint32_t> m_equippedAttachSlotIds;     // +0x10  skeleton attach/joint ids  VERIFIED
    std::vector<S_EquipmentSlotIdWrapper> m_equipmentSlotCache;  // +0x28  cached slot entries  VERIFIED (16B elems)
    std::vector<C_Item*> m_equippedItems;              // +0x40  VERIFIED
    // slot id (EquipmentSlotId, 4B key) -> clothing item WUID (8B value). Node 32B => 16B pair. VERIFIED.
    std::unordered_map<uint32_t, wh::framework::WUID> m_clothing;  // +0x58  (0x40)
    C_Item*  m_handSlots[8];                            // +0x98  per-hand-slot item ptrs  VERIFIED
    std::vector<bool> m_handSlotOccupied;              // +0xD8  size 8  VERIFIED
    float    m_totalWeight;                            // +0xF8  VERIFIED
    float    m_wornWeight;                             // +0xFC  VERIFIED
    std::vector<I_EquipmentObserver*> m_changeObservers;  // +0x100  observer list  VERIFIED
    uint64_t m_dispatchDepth;                          // +0x118  observer-dispatch reentrancy counter  VERIFIED
    bool     m_observersHasRemovals;                   // +0x120  pending null-removal flag  VERIFIED
    bool     m_observersNeedsClear;                    // +0x121  pending shrink flag  VERIFIED
    uint8_t  _pad122[6];                               // +0x122
    uint32_t m_recomputeSuspendCount;                  // +0x128  weight-recompute suspend counter  VERIFIED
    uint8_t  _pad12C[4];                               // +0x12C
};
static_assert(sizeof(C_EquipmentManager) == 0x130, "C_EquipmentManager must be 0x130");

}  // namespace wh::entitymodule
