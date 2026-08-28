#pragma once
#include <cstddef>
#include <cstdint>

#include "../rttr/rttr_enable.h"
#include "C_ItemPropertyDescriptor.h"
#include "S_ShieldIngredientName.h"

namespace wh::entitymodule {

class C_ShieldIngredientDescriptor : public C_ItemPropertyDescriptor {
public:
    ~C_ShieldIngredientDescriptor() override; // [0] 0x181F0DA00
    std::uint32_t GetMatchFailReason(
        C_Item* item, std::uint32_t flags) const override; // [4] 0x181F0E6E0
    RTTR_ENABLE(C_ItemPropertyDescriptor) // [6..8]

    S_ShieldIngredientName m_pattern; // +0x38
    S_ShieldIngredientName m_color1;  // +0x40
    S_ShieldIngredientName m_color2;  // +0x48
    S_ShieldIngredientName m_symbol;  // +0x50
};

static_assert(offsetof(C_ShieldIngredientDescriptor, m_pattern) == 0x38,
              "C_ShieldIngredientDescriptor::m_pattern offset mismatch");
static_assert(offsetof(C_ShieldIngredientDescriptor, m_symbol) == 0x50,
              "C_ShieldIngredientDescriptor::m_symbol offset mismatch");
static_assert(sizeof(C_ShieldIngredientDescriptor) == 0x58,
              "C_ShieldIngredientDescriptor size mismatch");

} // namespace wh::entitymodule
