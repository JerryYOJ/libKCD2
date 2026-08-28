#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_StateProxy.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../questmodule/S_Tracker.h"
#include "I_InventoryListener.h"
#include "I_ItemDescriptor.h"

namespace wh::entitymodule {

class C_Inventory;
class C_Item;

using C_ItemDescriptorTriggerBase = wh::conceptmodule::C_StateProxy<
    wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>>;

#pragma pack(push, 4)
class C_ItemDescriptorTrigger
    : public C_ItemDescriptorTriggerBase,
      public I_InventoryListener {
public:
    C_ItemDescriptorTrigger();                                           // 0x181218D8C
    ~C_ItemDescriptorTrigger() override;                                 // [0]
    RTTR_ENABLE(C_ItemDescriptorTriggerBase)                             // [5..7], vtable 0x183B374E0

    wh::conceptmodule::C_TypedPortRef<C_Inventory*> m_inventory;         // +0xC0 RTTR "Inventory"
    wh::conceptmodule::C_TypedPortRef<
        std::shared_ptr<I_ItemDescriptor>> m_itemDescriptor;             // +0x100 RTTR "ItemDescriptor"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onTargetAmountAcquire;           // +0x140
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAcquire;                       // +0x180
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onTargetAmountLose;              // +0x1C0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onLose;                          // +0x200
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAfterLose;                     // +0x240
    wh::conceptmodule::C_TypedPortRef<
        wh::questmodule::S_Tracker> m_tracker;                           // +0x280 RTTR "Tracker"
    wh::conceptmodule::C_TypedPortRef<C_Item*> m_item;                   // +0x2C0 RTTR "Item"
    std::uint16_t m_unknown300;                                          // +0x300 ctor 0
    bool m_unknown302;                                                   // +0x302 ctor 0
    std::uint8_t m_padding303;                                           // +0x303
    std::uint64_t m_unknown304;                                          // +0x304 ctor 0; pack(4)
    std::uint8_t m_unknown30C[0xC];                                      // +0x30C
    std::uint64_t m_unknown318;                                          // +0x318
    std::uint64_t m_unknown320;                                          // +0x320
    std::uint64_t m_unknown328;                                          // +0x328
    std::uint64_t m_unknown330;                                          // +0x330
    std::uint64_t m_unknown338;                                          // +0x338
};
#pragma pack(pop)

static_assert(offsetof(C_ItemDescriptorTrigger, m_inventory) == 0xC0,
              "C_ItemDescriptorTrigger::m_inventory offset mismatch");
static_assert(offsetof(C_ItemDescriptorTrigger, m_itemDescriptor) == 0x100,
              "C_ItemDescriptorTrigger::m_itemDescriptor offset mismatch");
static_assert(offsetof(C_ItemDescriptorTrigger, m_tracker) == 0x280,
              "C_ItemDescriptorTrigger::m_tracker offset mismatch");
static_assert(offsetof(C_ItemDescriptorTrigger, m_item) == 0x2C0,
              "C_ItemDescriptorTrigger::m_item offset mismatch");
static_assert(offsetof(C_ItemDescriptorTrigger, m_unknown304) == 0x304,
              "C_ItemDescriptorTrigger::m_unknown304 offset mismatch");
static_assert(sizeof(C_ItemDescriptorTrigger) == 0x340,
              "C_ItemDescriptorTrigger size mismatch");

} // namespace wh::entitymodule
