#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../conceptmodule/C_RuntimeState.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_ItemDelivery.h"
#include "E_DeliveryResult.h"

namespace wh::entitymodule {

class C_Item;

class C_ItemDeliveryHandler : public wh::conceptmodule::C_RuntimeState {
public:
    ~C_ItemDeliveryHandler() override;                                   // [0]
    RTTR_ENABLE(wh::conceptmodule::C_RuntimeState)                       // [5..7], vtable 0x183B76E28
    void OnDeserializationComplete() override;                           // [41]

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_beginDelivery;                   // +0x40 RTTR "BeginDelivery"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnknown80;                     // +0x80 registrar used class name
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnknownC0;                     // +0xC0
    wh::conceptmodule::C_TypedPortRef<
        std::shared_ptr<C_ItemDelivery>> m_itemDelivery;                 // +0x100 RTTR "ItemDelivery"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onResultAvailable;               // +0x140 RTTR "OnResultAvailable"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnknown180;                    // +0x180
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnknown1C0;                    // +0x1C0
    wh::conceptmodule::C_TypedPortRef<
        E_DeliveryResult::Type> m_result;                                // +0x200 RTTR "OnResultAvailable"
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<C_Item*>> m_deliveryItems;                           // +0x240 RTTR "DeliveryItems"
    std::uint8_t m_unknown280[0x18];                                     // +0x280
};

static_assert(offsetof(C_ItemDeliveryHandler, m_beginDelivery) == 0x40,
              "C_ItemDeliveryHandler::m_beginDelivery offset mismatch");
static_assert(offsetof(C_ItemDeliveryHandler, m_itemDelivery) == 0x100,
              "C_ItemDeliveryHandler::m_itemDelivery offset mismatch");
static_assert(offsetof(C_ItemDeliveryHandler, m_result) == 0x200,
              "C_ItemDeliveryHandler::m_result offset mismatch");
static_assert(offsetof(C_ItemDeliveryHandler, m_deliveryItems) == 0x240,
              "C_ItemDeliveryHandler::m_deliveryItems offset mismatch");
static_assert(sizeof(C_ItemDeliveryHandler) == 0x298,
              "C_ItemDeliveryHandler size mismatch");

} // namespace wh::entitymodule
