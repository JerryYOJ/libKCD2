#pragma once
#include <cstdint>
#include "C_InventoryBase.h"
#include "C_ItemCollection.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::entitymodule::C_Inventory : C_InventoryBase, C_ItemCollection -- KCD2 1.5.6 (kd7u).  sizeof 0x188.
// -----------------------------------------------
// RTTI .?AVC_Inventory@entitymodule@wh@@  primary vtable 0x183A2D858 (24 slots)  ctor sub_1803A4A1C
// C_ItemCollection secondary sub-vtable 0x183A2D698 @+0xE8.
//
// [FUNDAMENTAL vs KCD1] KCD1 was a flat 0xC8 POD (WUID-set); KCD2 is a polymorphic item-holder/collection.
//   KCD1's item WUID-set -> std::vector<C_Item*> m_items (in C_InventoryBase); KCD1's listener
//   vector + guard -> two embedded C_DependentListeners registries (inventory @+0x38, collection @+0xF0).
//   KCD1's inline owner WUID/name are gone -- owner is resolved via the manager + the +0x160 registry key.

namespace wh::entitymodule {

class C_Inventory
    : public C_InventoryBase       // +0x00   (0xE8: vtable + item lists + inventory listeners)
    , public C_ItemCollection      // +0xE8   (0x70: sub-vtable + collection listeners)
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Inventory;

    E_ItemHolderType GetHolderType() const override; // [1] 0x180838AE0
    void* _vf4() override; // [4] 0x1805F5DA0
    void* _vf5() override; // [5] 0x1805F5DA0
    bool _vf6() const override; // [6] 0x18041A6A0
    const framework::WUID& GetWuid() const override; // [7] 0x1808F50F0
    void _vf8(C_Item* item, E_ItemHolderChangeFlags flags,
              std::uint32_t amount) override; // [8] 0x180479420
    void _vf11(C_Item* item, E_ItemHolderChangeFlags flags,
               std::uint32_t amount) override; // [11] 0x180465E88
    void _vf12(S_ItemClass* itemClass, E_ItemHolderChangeFlags flags,
               std::uint32_t amount,
               framework::WUID itemWuid) override; // [12] 0x1804794E0
    bool _vf15() const override; // [15] 0x18041A6A0
    bool _vf16() const override; // [16] 0x18041A6A0
    void _vf17(C_Item* consumedItem,
               C_Item* survivingItem) override; // [17] 0x1808F47C0
    void _vf18(C_Item* survivingItem,
               framework::WUID consumedItemWuid,
               std::uint32_t consumedAmount) override; // [18] 0x1808F3328
    void _vf19(C_Item* sourceItem,
               C_Item* splitItem) override; // [19] 0x1808F0CD8
    void _vf20(C_Item* item, std::int32_t amountDelta,
               std::uint32_t changeMask) override; // [20] 0x1804667CC

    RTTR_ENABLE(C_InventoryBase, C_ItemCollection) // [21..23]

    wh::framework::WUID m_wuid;                 // +0x158  inventory's own WUID registry key (tag 3 = Inventory); acquire sub_1823D154C stores v4|0x0300000000000000
    CryGUID  m_guid;                           // +0x160  16-byte registry key (the C_InventoryManager map key)  VERIFIED (key)
    CryStringT<char> m_sharedState;            // +0x170  CryString; ctor inits to empty shared static (_emptyHeader+12), dtor sub_1804FC624 decrefs SStringData header @ ptr-12
    uint16_t m_flags16;                        // +0x178  (ctor 0)
    uint8_t  m_flag;                           // +0x17A  init 1 (KCD1 m_flag2)
    uint8_t  _pad17B[5];                       // +0x17B
    void*    m_ownerRef;                       // +0x180  owned polymorphic obj: dtor sub_1803A4944 calls (*(vtbl+0x28))(obj, 1) -- virtual disposal with flag 1, C_Inventory owns/deletes it (slot semantics INFERRED; pointee class UNVERIFIED)
};
static_assert(sizeof(C_Inventory) == 0x188, "C_Inventory must be 0x188");

}  // namespace wh::entitymodule
