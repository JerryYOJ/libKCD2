#pragma once
#include <cstddef>
#include <cstdint>

#include "../rttr/rttr_enable.h"
#include "C_ItemPropertyDescriptor.h"
#include "E_ItemCategory.h"
#include "S_ArmorSurfaceName.h"

namespace wh::entitymodule {

class C_ItemCategoryDescriptor : public C_ItemPropertyDescriptor {
public:
    ~C_ItemCategoryDescriptor() override; // [0] 0x1815CB748
    std::uint32_t GetMatchFailReason(
        C_Item* item, std::uint32_t flags) const override; // [4] 0x18096F23C
    RTTR_ENABLE(C_ItemPropertyDescriptor) // [6..8]

    E_ItemCategory m_category;           // +0x38
    std::int32_t m_type;                 // +0x3C
    std::int32_t m_subtype;              // +0x40
    bool m_negateCategory;               // +0x44
    bool m_negateType;                   // +0x45
    bool m_negateSubtype;                // +0x46
    std::uint8_t m_padding47;            // +0x47
    CryStringT<char> m_tag;              // +0x48
    bool m_negateTag;                    // +0x50
    std::uint8_t m_padding51[3];         // +0x51
    float m_minCharisma;                 // +0x54
    float m_maxCharisma;                 // +0x58
    bool m_negateCharisma;               // +0x5C
    std::uint8_t m_padding5D[3];         // +0x5D
    float m_minBlood;                    // +0x60
    float m_maxBlood;                    // +0x64
    bool m_negateBlood;                  // +0x68
    std::uint8_t m_padding69[7];         // +0x69
    S_ArmorSurfaceName m_armorSurfaceName; // +0x70
    bool m_negateArmorSurface;           // +0x78
    std::uint8_t m_padding79[7];         // +0x79
};

static_assert(offsetof(C_ItemCategoryDescriptor, m_category) == 0x38,
              "C_ItemCategoryDescriptor::m_category offset mismatch");
static_assert(offsetof(C_ItemCategoryDescriptor, m_tag) == 0x48,
              "C_ItemCategoryDescriptor::m_tag offset mismatch");
static_assert(offsetof(C_ItemCategoryDescriptor, m_armorSurfaceName) == 0x70,
              "C_ItemCategoryDescriptor::m_armorSurfaceName offset mismatch");
static_assert(sizeof(C_ItemCategoryDescriptor) == 0x80,
              "C_ItemCategoryDescriptor size mismatch");

} // namespace wh::entitymodule
