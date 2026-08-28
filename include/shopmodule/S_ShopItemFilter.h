#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::shopmodule::S_ShopItemFilter
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x20. No vtable.
// -----------------------------------------------

namespace wh::shopmodule {

struct S_ShopItemFilter {
    CryStringT<char> m_filter;                            // +0x00 RTTR "filter"
    std::uint8_t _pad08[8];                               // +0x08
    float m_price_buy_multiplier;                         // +0x10 RTTR "price_buy_multiplier"
    float m_price_sell_multiplier;                        // +0x14 RTTR "price_sell_multiplier"
    bool m_exclude;                                       // +0x18 RTTR "exclude"
    std::uint8_t _pad19[7];                               // +0x19
};

static_assert(offsetof(S_ShopItemFilter, m_filter) == 0x00,
              "S_ShopItemFilter::m_filter offset mismatch");
static_assert(offsetof(S_ShopItemFilter, m_price_buy_multiplier) == 0x10,
              "S_ShopItemFilter::m_price_buy_multiplier offset mismatch");
static_assert(sizeof(S_ShopItemFilter) == 0x20,
              "S_ShopItemFilter size mismatch");

}  // namespace wh::shopmodule
