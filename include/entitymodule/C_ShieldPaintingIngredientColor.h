#pragma once
#include <cstddef>
#include <cstdint>

#include "../rttr/rttr_enable.h"
#include "C_ShieldPaintingIngredientBase.h"

namespace wh::entitymodule {

class C_ShieldPaintingIngredientColor
    : public C_ShieldPaintingIngredientBase {
public:
    ~C_ShieldPaintingIngredientColor() override; // [0] 0x181EB2A80
    E_ShieldPaintingIngredientKind GetKind() const override; // [6] returns Color
    std::int32_t GetCategoryId() const override; // [7] returns -1
    RTTR_ENABLE(C_ShieldPaintingIngredientBase) // [8..10]

    CryStringT<char> m_materialName; // +0x20 RTTR "MaterialName"
};

static_assert(offsetof(C_ShieldPaintingIngredientColor, m_materialName) == 0x20,
              "C_ShieldPaintingIngredientColor::m_materialName offset mismatch");
static_assert(sizeof(C_ShieldPaintingIngredientColor) == 0x28,
              "C_ShieldPaintingIngredientColor size mismatch");

} // namespace wh::entitymodule
