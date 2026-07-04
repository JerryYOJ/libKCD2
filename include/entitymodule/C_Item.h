#pragma once
#include <cstdint>
#include "../framework/I_BindableObject.h"
#include "../framework/WUID.h"
#include "../crysystem/EntityEventListenerWithCleanup.h"
#include "../Offsets/vtables/IEntity.h"   // Offsets::IEntity
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::entitymodule::C_Item -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0xA8.
// -----------------------------------------------
// RTTI .?AVC_Item@entitymodule@wh@@  primary vtable 0x183A2DA88  factory sub_181EEDF50  dtor sub_180477554
// Bases (CHD, MI): I_BindableObject @+0x00 (primary), EntityEventListenerWithCleanup @+0x08.
// Own members from +0x28. This is an event-listener + bindable object, NOT a C_Actor-style entity
// extension (only 2 vtable pointers).
//
// [FUNDAMENTAL vs KCD1] sizeof 0xE0 -> 0xA8: KCD1's embedded S_ItemRuntimeDataTable (0x70) is gone --
//   per-item runtime data is now a single lazily-created pointer m_pRuntimeData @+0x58. The KCD1 u32
//   m_entityId is superseded by the IEntity* at +0x88 (id read from entity+0x30).

namespace wh::entitymodule {

class  S_ItemData;
class  I_ItemRuntimeData;
class  C_ItemManager;
class  I_Inventory;

class C_Item
    : public wh::framework::I_BindableObject               // +0x00  (primary vtable)
    , public ::EntityEventListenerWithCleanup              // +0x08  (vtable + event vector, 0x20)
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Item;
    uint8_t  m_state;                                  // +0x28  init 5 (state/enum; no reader isolated)
    uint8_t  _pad29[7];                                // +0x29
    wh::framework::WUID m_wuid;                        // +0x30  registry key (tag 2 = Item)  VERIFIED
    CryGUID  m_classGuid;                              // +0x38  item class guid  VERIFIED
    S_ItemData* m_pClassData;                          // +0x48  class definition (GetClassDef)  VERIFIED
    int32_t  m_amount;                                 // +0x50  stack count (init 1)  VERIFIED
    float    m_health;                                 // +0x54  init 1.0 (GetHealth)  VERIFIED
    I_ItemRuntimeData* m_pRuntimeData;                 // +0x58  lazily created per-item runtime data  VERIFIED
    uint32_t m_flags;                                  // +0x60  bit flags  VERIFIED
    float    m_condition;                              // +0x64  wear/condition, clamped [0,1] (tentative)
    wh::framework::WUID m_owner;                       // +0x68  owner handle (stolen/ownership test)  VERIFIED
    uint64_t m_ownerExtra;                             // +0x70  2nd qword of the 16-byte owner handle
    void*    m_pOwnerContext;                          // +0x78  lazily-set ownership context (type UNVERIFIED)
    int64_t  m_expiry;                                 // +0x80  TTL sentinel init INT64_MAX  VERIFIED
    Offsets::IEntity* m_pLinkedEntity;                 // +0x88  spawned entity (OnEntityEvent)  VERIFIED
    C_ItemManager* m_pItemManager;                     // +0x90  owning item manager back-ptr (tentative)
    I_Inventory* m_pInventory;                         // +0x98  current container back-ptr (tentative)
    uint32_t m_param0xA0;                              // +0xA0  init 42 (no reader isolated; UNVERIFIED)
    uint32_t _padA4;                                   // +0xA4
};
static_assert(sizeof(C_Item) == 0xA8, "C_Item must be 0xA8");

}  // namespace wh::entitymodule
