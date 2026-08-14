#pragma once

#include <unordered_map>
#include "../framework/HashPrimitives.h"
#include "../framework/WUID.h"

namespace wh::shopmodule {

class C_Shop;

// Descriptive name: the binary exposes this non-polymorphic registry but no source symbol.
class C_ShopRegistry {
public:
    C_Shop* FindByWuid(framework::WUID wuid);

    std::unordered_map<framework::WUID, C_Shop*,
                       shared::S_DefaultHash<framework::WUID>> m_shopsByWuid;
    std::uint8_t _unknown40[0x40];
    C_Shop* m_pDefaultShop; // +0x80
};
static_assert(sizeof(C_ShopRegistry) == 0x88, "C_ShopRegistry must be 0x88");

}  // namespace wh::shopmodule
