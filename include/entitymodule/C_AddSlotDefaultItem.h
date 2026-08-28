#pragma once

#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>

#include "../conceptmodule/C_ExternalPartialActivationEffect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "C_ItemSlot.h"

namespace wh::entitymodule {

class C_AddSlotDefaultItem
    : public wh::conceptmodule::C_ExternalPartialActivationEffect<C_ItemSlot> {
public:
    ~C_AddSlotDefaultItem() override;                                    // [0]
    RTTR_ENABLE(wh::conceptmodule::C_ExternalPartialActivationEffect<C_ItemSlot>) // [5..7], vtable 0x183B93950
    void ApplyToTarget(
        C_ItemSlot* target,
        CryStringT<char> const& key,
        bool initialApplication) override;                               // [46]
    void RemoveFromTarget(
        C_ItemSlot* target,
        CryStringT<char> const& key) override;                           // [47]
    std::unordered_set<C_ItemSlot*> GetAppliedTargets() const override;  // [48]

    wh::conceptmodule::C_TypedPortRef<bool> m_disableRestock;            // +0xC8 RTTR "DisableRestock"
    wh::conceptmodule::C_TypedPortRef<std::uint32_t> m_quality;          // +0x108 RTTR "Quality"
    wh::conceptmodule::C_TypedPortRef<float> m_health;                   // +0x148 RTTR "Health"
    wh::conceptmodule::C_TypedPortRef<float> m_condition;                // +0x188 RTTR "Condition"
    std::unordered_map<C_ItemSlot*, void*> m_appliedItems;               // +0x1C8 mapped type unresolved
};

static_assert(offsetof(C_AddSlotDefaultItem, m_disableRestock) == 0xC8,
              "C_AddSlotDefaultItem::m_disableRestock offset mismatch");
static_assert(offsetof(C_AddSlotDefaultItem, m_quality) == 0x108,
              "C_AddSlotDefaultItem::m_quality offset mismatch");
static_assert(offsetof(C_AddSlotDefaultItem, m_health) == 0x148,
              "C_AddSlotDefaultItem::m_health offset mismatch");
static_assert(offsetof(C_AddSlotDefaultItem, m_condition) == 0x188,
              "C_AddSlotDefaultItem::m_condition offset mismatch");
static_assert(offsetof(C_AddSlotDefaultItem, m_appliedItems) == 0x1C8,
              "C_AddSlotDefaultItem::m_appliedItems offset mismatch");
static_assert(sizeof(C_AddSlotDefaultItem) == 0x208,
              "C_AddSlotDefaultItem size mismatch");

} // namespace wh::entitymodule
