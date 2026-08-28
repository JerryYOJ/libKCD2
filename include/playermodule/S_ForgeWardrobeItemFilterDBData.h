#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::playermodule {

struct S_ForgeWardrobeItemFilterDBData {
    std::int32_t m_id;                                         // +0x00 id
    std::uint8_t m_padding04[4];                              // +0x04
    const char* m_assetName;                                   // +0x08 asset_name
    const char* m_itemFilter;                                  // +0x10 item_filter
    const char* m_itemTag;                                     // +0x18 item_tag
};

static_assert(sizeof(S_ForgeWardrobeItemFilterDBData) == 0x20,
              "S_ForgeWardrobeItemFilterDBData size mismatch");
static_assert(offsetof(S_ForgeWardrobeItemFilterDBData, m_assetName) == 0x08,
              "S_ForgeWardrobeItemFilterDBData asset offset mismatch");

} // namespace wh::playermodule
