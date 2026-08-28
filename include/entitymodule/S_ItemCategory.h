#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {
class S_ItemCategory {
public:
    RTTR_ENABLE()  // [0..2]
    std::int32_t m_item_category;  // +0x8 RTTR "wh::entitymodule::item_category"
    std::uint8_t m_unknown0C[0x4];                  // +0xC
    CryStringT<char> m_item_category_name;  // +0x10 RTTR "item_category_name"
    CryStringT<char> m_item_type_custom_enum_name;  // +0x18 RTTR "item_type_custom_enum_name"
    CryStringT<char> m_item_subtype_custom_enum_name;  // +0x20 RTTR "item_subtype_custom_enum_name"
};

static_assert(offsetof(S_ItemCategory, m_item_subtype_custom_enum_name) == 0x20, "S_ItemCategory::m_item_subtype_custom_enum_name offset mismatch");
static_assert(offsetof(S_ItemCategory, m_item_type_custom_enum_name) == 0x18, "S_ItemCategory::m_item_type_custom_enum_name offset mismatch");
static_assert(offsetof(S_ItemCategory, m_item_category_name) == 0x10, "S_ItemCategory::m_item_category_name offset mismatch");
static_assert(offsetof(S_ItemCategory, m_item_category) == 0x8, "S_ItemCategory::m_item_category offset mismatch");
static_assert(sizeof(S_ItemCategory) == 0x28, "S_ItemCategory size mismatch");

}  // namespace wh::entitymodule
