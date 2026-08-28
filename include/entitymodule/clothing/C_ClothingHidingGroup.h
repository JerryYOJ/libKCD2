#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"

namespace wh::entitymodule::clothing {
class C_ClothingHidingGroup {
public:
    virtual ~C_ClothingHidingGroup();
    RTTR_ENABLE()  // [1..3]
    CryStringT<char> m_name;  // +0x8 RTTR "Name"
    std::uint8_t m_index;  // +0x10 RTTR "Index"
    std::uint8_t m_unknown11[0x7];                  // +0x11
    bool m_systemOnly;  // +0x18 RTTR "SystemOnly"
    std::uint8_t m_unknown19[0x7];                  // +0x19
};

static_assert(offsetof(C_ClothingHidingGroup, m_systemOnly) == 0x18, "C_ClothingHidingGroup::m_systemOnly offset mismatch");
static_assert(offsetof(C_ClothingHidingGroup, m_index) == 0x10, "C_ClothingHidingGroup::m_index offset mismatch");
static_assert(offsetof(C_ClothingHidingGroup, m_name) == 0x8, "C_ClothingHidingGroup::m_name offset mismatch");
static_assert(sizeof(C_ClothingHidingGroup) == 0x20, "C_ClothingHidingGroup size mismatch");

}  // namespace wh::entitymodule::clothing
