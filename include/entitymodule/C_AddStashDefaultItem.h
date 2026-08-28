#pragma once

#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>

#include "../conceptmodule/C_ExternalPartialActivationEffect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "C_Stash.h"
#include "E_AddDefaultItemMode.h"
#include "S_ItemClassGUID.h"

namespace wh::entitymodule {

class C_AddStashDefaultItem
    : public wh::conceptmodule::C_ExternalPartialActivationEffect<C_Stash> {
public:
    ~C_AddStashDefaultItem() override;                                   // [0]
    RTTR_ENABLE(wh::conceptmodule::C_ExternalPartialActivationEffect<C_Stash>) // [5..7], vtable 0x183A74C10
    void ApplyToTarget(
        C_Stash* target,
        CryStringT<char> const& key,
        bool initialApplication) override;                               // [46]
    void RemoveFromTarget(
        C_Stash* target,
        CryStringT<char> const& key) override;                           // [47]
    std::unordered_set<C_Stash*> GetAppliedTargets() const override;     // [48]

    wh::conceptmodule::C_TypedPortRef<S_ItemClassGUID> m_itemClass;      // +0xC8 RTTR "ItemClass"
    wh::conceptmodule::C_TypedPortRef<bool> m_disableRestock;            // +0x108 RTTR "DisableRestock"
    wh::conceptmodule::C_TypedPortRef<std::uint32_t> m_amount;           // +0x148 RTTR "Amount"
    wh::conceptmodule::C_TypedPortRef<std::uint32_t> m_quality;          // +0x188 RTTR "Quality"
    wh::conceptmodule::C_TypedPortRef<float> m_health;                   // +0x1C8 RTTR "Health"
    wh::conceptmodule::C_TypedPortRef<float> m_condition;                // +0x208 RTTR "Condition"
    wh::conceptmodule::C_TypedPortRef<E_AddDefaultItemMode::Type> m_mode; // +0x248 RTTR "Mode"
    std::unordered_map<C_Stash*, void*> m_appliedItems;                  // +0x288 mapped type unresolved
};

static_assert(offsetof(C_AddStashDefaultItem, m_itemClass) == 0xC8,
              "C_AddStashDefaultItem::m_itemClass offset mismatch");
static_assert(offsetof(C_AddStashDefaultItem, m_disableRestock) == 0x108,
              "C_AddStashDefaultItem::m_disableRestock offset mismatch");
static_assert(offsetof(C_AddStashDefaultItem, m_amount) == 0x148,
              "C_AddStashDefaultItem::m_amount offset mismatch");
static_assert(offsetof(C_AddStashDefaultItem, m_mode) == 0x248,
              "C_AddStashDefaultItem::m_mode offset mismatch");
static_assert(offsetof(C_AddStashDefaultItem, m_appliedItems) == 0x288,
              "C_AddStashDefaultItem::m_appliedItems offset mismatch");
static_assert(sizeof(C_AddStashDefaultItem) == 0x2C8,
              "C_AddStashDefaultItem size mismatch");

} // namespace wh::entitymodule
