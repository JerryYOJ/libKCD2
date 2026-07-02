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
//   KCD1's item WUID-set -> std::vector<C_ItemHolder*> m_items (in C_InventoryBase); KCD1's listener
//   vector + guard -> two embedded C_DependentListeners registries (inventory @+0x38, collection @+0xF0).
//   KCD1's inline owner WUID/name are gone -- owner is resolved via the manager + the +0x160 registry key.

namespace wh::entitymodule {

class C_Inventory
    : public C_InventoryBase       // +0x00   (0xE8: vtable + item lists + inventory listeners)
    , public C_ItemCollection      // +0xE8   (0x70: sub-vtable + collection listeners)
{
public:
    void*    m_registryOrManager;              // +0x158  owning manager/registry back-ptr (runtime-set)  tentative
    CryGUID  m_guid;                           // +0x160  16-byte registry key (the C_InventoryManager map key)  VERIFIED (key)
    void*    m_sharedState;                    // +0x170  intrusive-refcounted shared default block
    uint16_t m_flags16;                        // +0x178  (ctor 0)
    uint8_t  m_flag;                           // +0x17A  init 1 (KCD1 m_flag2)
    uint8_t  _pad17B[5];                       // +0x17B
    void*    m_ownerRef;                       // +0x180  ref-counted owner handle (Released in dtor)  tentative type
};
static_assert(sizeof(C_Inventory) == 0x188, "C_Inventory must be 0x188");

}  // namespace wh::entitymodule
