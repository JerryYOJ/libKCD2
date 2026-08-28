#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_ShopItemFilter.h"

// -----------------------------------------------
// wh::shopmodule::S_ShopDBData
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x38. No vtable.
// -----------------------------------------------

namespace wh::shopmodule {

struct S_ShopDBData {
    std::int32_t m_shop_id;                               // +0x00 RTTR "shop_id"
    std::uint8_t _pad04[4];                               // +0x04
    CryStringT<char> m_shop_name;                         // +0x08 RTTR "shop_name"
    std::uint16_t m_restock_period;                       // +0x10 RTTR "restock_period"
    std::uint8_t _pad12[6];                               // +0x12
    std::vector<S_ShopItemFilter> m_shopItemFilters;      // +0x18 RTTR "ShopItemFilters"
    CryStringT<char> m_inventory_preset;                  // +0x30 RTTR "inventory_preset"
};

static_assert(offsetof(S_ShopDBData, m_shop_id) == 0x00,
              "S_ShopDBData::m_shop_id offset mismatch");
static_assert(offsetof(S_ShopDBData, m_shopItemFilters) == 0x18,
              "S_ShopDBData::m_shopItemFilters offset mismatch");
static_assert(offsetof(S_ShopDBData, m_inventory_preset) == 0x30,
              "S_ShopDBData::m_inventory_preset offset mismatch");
static_assert(sizeof(S_ShopDBData) == 0x38,
              "S_ShopDBData size mismatch");

}  // namespace wh::shopmodule
