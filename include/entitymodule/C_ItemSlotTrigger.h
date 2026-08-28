#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_StateProxy.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_ItemSlot.h"
#include "I_ItemSlotListener.h"

namespace wh::entitymodule {

class C_Item;

using C_ItemSlotTriggerBase = wh::conceptmodule::C_StateProxy<
    wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>>;

class C_ItemSlotTrigger
    : public C_ItemSlotTriggerBase,
      public I_ItemSlotListener {
public:
    C_ItemSlotTrigger();                                                 // 0x18121877C
    ~C_ItemSlotTrigger() override;                                       // [0]
    RTTR_ENABLE(C_ItemSlotTriggerBase)                                   // [5..7], vtable 0x183B37B98

    void OnAfterAcquire(C_Item* item) override;                          // +0xB8 [0] 0x1816571A8
    void OnBeforeLose(C_Item* item) override;                            // +0xB8 [1] 0x181657194
    void OnSlotItem(C_Item* item) override;                              // +0xB8 [2] 0x1819DF2F0

    wh::conceptmodule::C_TypedPortRef<C_ItemSlot*> m_itemSlot;           // +0xC0 RTTR "ItemSlot"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAfterAcquire;                  // +0x100 RTTR "OnAfterAcquire"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onBeforeLose;                    // +0x140 RTTR "OnBeforeLose"
    wh::conceptmodule::C_TypedPortRef<C_Item*> m_item;                   // +0x180 RTTR "Item"
    C_Item* m_activeItem;                                                // +0x1C0
};

static_assert(sizeof(C_ItemSlotTriggerBase) == 0xB8,
              "C_ItemSlotTriggerBase size mismatch");
static_assert(offsetof(C_ItemSlotTrigger, m_itemSlot) == 0xC0,
              "C_ItemSlotTrigger::m_itemSlot offset mismatch");
static_assert(offsetof(C_ItemSlotTrigger, m_onAfterAcquire) == 0x100,
              "C_ItemSlotTrigger::m_onAfterAcquire offset mismatch");
static_assert(offsetof(C_ItemSlotTrigger, m_item) == 0x180,
              "C_ItemSlotTrigger::m_item offset mismatch");
static_assert(offsetof(C_ItemSlotTrigger, m_activeItem) == 0x1C0,
              "C_ItemSlotTrigger::m_activeItem offset mismatch");
static_assert(sizeof(C_ItemSlotTrigger) == 0x1C8,
              "C_ItemSlotTrigger size mismatch");

} // namespace wh::entitymodule
