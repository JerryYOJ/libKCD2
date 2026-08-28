#pragma once
#include <cstddef>
#include <cstdint>

#include "../rttr/rttr_enable.h"
#include "C_ShieldPaintingIngredientWithTexture.h"

namespace wh::entitymodule {

class C_ShieldPaintingIngredientPattern
    : public C_ShieldPaintingIngredientWithTexture {
public:
    ~C_ShieldPaintingIngredientPattern() override; // [0] 0x181EB2AC0
    E_ShieldPaintingIngredientKind GetKind() const override; // [6] returns Pattern
    std::int32_t GetCategoryId() const override; // [7] returns m_subClass
    RTTR_ENABLE(C_ShieldPaintingIngredientWithTexture) // [8..10]

    std::int32_t m_subClass;   // +0x30 RTTR "SubClass"; initialized -1
    std::uint32_t m_padding34; // +0x34
};

static_assert(offsetof(C_ShieldPaintingIngredientPattern, m_subClass) == 0x30,
              "C_ShieldPaintingIngredientPattern::m_subClass offset mismatch");
static_assert(sizeof(C_ShieldPaintingIngredientPattern) == 0x38,
              "C_ShieldPaintingIngredientPattern size mismatch");

} // namespace wh::entitymodule
