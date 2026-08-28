#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::playermodule {

struct S_ForgeWardrobeItemFilter {
    std::int32_t m_id;                                         // +0x00
    std::uint8_t m_padding04[4];                              // +0x04
    CryStringT<char> m_assetName;                              // +0x08
    CryStringT<char> m_itemFilter;                             // +0x10
    CryStringT<char> m_itemTag;                                // +0x18
};

static_assert(sizeof(S_ForgeWardrobeItemFilter) == 0x20,
              "S_ForgeWardrobeItemFilter size mismatch");
static_assert(offsetof(S_ForgeWardrobeItemFilter, m_assetName) == 0x08,
              "S_ForgeWardrobeItemFilter asset offset mismatch");
static_assert(offsetof(S_ForgeWardrobeItemFilter, m_itemTag) == 0x18,
              "S_ForgeWardrobeItemFilter tag offset mismatch");

} // namespace wh::playermodule
