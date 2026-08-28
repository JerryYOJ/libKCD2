#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../conceptmodule/C_ExternalPartialActivationEffect.h"
#include "../entitymodule/I_ItemCollectionListener.h"
#include "../entitymodule/S_ItemClassGUID.h"
#include "C_Shop.h"

namespace wh::shopmodule {

class C_AddShopDefaultItem
    : public wh::conceptmodule::C_ExternalPartialActivationEffect<C_Shop>,
      public wh::entitymodule::I_ItemCollectionListener {
public:
    ~C_AddShopDefaultItem() override;                        // [0] 0x1817816A4
    RTTR_ENABLE(wh::conceptmodule::C_ExternalPartialActivationEffect<C_Shop>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                   // [27] 0x182EF36D4
    void OnEffectActivate() override;                        // [43] 0x182EF37A4
    void OnEffectDeactivate() override;                      // [44] 0x182EF3A1C
    void ApplyToTarget(
        C_Shop* target,
        CryStringT<char> const& key,
        bool initialApplication) override;                   // [46] 0x182EF3134
    void RemoveFromTarget(
        C_Shop* target,
        CryStringT<char> const& key) override;               // [47] 0x182EF3534
    std::unordered_set<C_Shop*> GetAppliedTargets() const override; // [48] 0x182EF3618

    void ItemCollectionListenerUnk4(
        wh::entitymodule::C_ItemCollection* collection) override; // listener [4] 0x182EF38F0

    wh::conceptmodule::C_TypedPortRef<wh::entitymodule::S_ItemClassGUID> m_itemClass; // +0xD0
    wh::conceptmodule::C_TypedPortRef<bool> m_disableRestock; // +0x110
    wh::conceptmodule::C_TypedPortRef<std::uint32_t> m_amount; // +0x150
    wh::conceptmodule::C_TypedPortRef<std::uint32_t> m_quality; // +0x190
    wh::conceptmodule::C_TypedPortRef<float> m_health;       // +0x1D0
    wh::conceptmodule::C_TypedPortRef<float> m_condition;    // +0x210
    std::unordered_map<C_Shop*, CryGUID> m_itemGuidsByShop;  // +0x250
};

static_assert(offsetof(C_AddShopDefaultItem, m_itemClass) == 0xD0,
              "C_AddShopDefaultItem::m_itemClass offset mismatch");
static_assert(offsetof(C_AddShopDefaultItem, m_disableRestock) == 0x110,
              "C_AddShopDefaultItem::m_disableRestock offset mismatch");
static_assert(offsetof(C_AddShopDefaultItem, m_amount) == 0x150,
              "C_AddShopDefaultItem::m_amount offset mismatch");
static_assert(offsetof(C_AddShopDefaultItem, m_condition) == 0x210,
              "C_AddShopDefaultItem::m_condition offset mismatch");
static_assert(offsetof(C_AddShopDefaultItem, m_itemGuidsByShop) == 0x250,
              "C_AddShopDefaultItem::m_itemGuidsByShop offset mismatch");
static_assert(sizeof(C_AddShopDefaultItem) == 0x290,
              "C_AddShopDefaultItem size mismatch");

}  // namespace wh::shopmodule
