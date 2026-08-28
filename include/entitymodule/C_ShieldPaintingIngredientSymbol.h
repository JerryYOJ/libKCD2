#pragma once
#include <cstddef>
#include <cstdint>

#include "../rttr/rttr_enable.h"
#include "C_ShieldPaintingIngredientWithTexture.h"

namespace wh::entitymodule {

class C_ShieldPaintingIngredientSymbol
    : public C_ShieldPaintingIngredientWithTexture {
public:
    ~C_ShieldPaintingIngredientSymbol() override; // [0] 0x181EB2B00
    E_ShieldPaintingIngredientKind GetKind() const override; // [6] returns Symbol
    std::int32_t GetCategoryId() const override; // [7] returns m_category
    RTTR_ENABLE(C_ShieldPaintingIngredientWithTexture) // [8..10]

    std::int32_t m_category;            // +0x30 RTTR "Category"; initialized -1
    std::uint32_t m_padding34;          // +0x34
    CryStringT<char> m_categoryName;    // +0x38 RTTR "Category"
    CryStringT<char> m_normalTexturePath; // +0x40 RTTR "NormalTexturePath"
    CryStringT<char> m_specularTexturePath; // +0x48 RTTR "SpecularTexturePath"
    ITexture* m_normalTexture;          // +0x50 EF_LoadTexture result
    ITexture* m_specularTexture;        // +0x58 EF_LoadTexture result
};

static_assert(offsetof(C_ShieldPaintingIngredientSymbol, m_category) == 0x30,
              "C_ShieldPaintingIngredientSymbol::m_category offset mismatch");
static_assert(offsetof(C_ShieldPaintingIngredientSymbol, m_categoryName) == 0x38,
              "C_ShieldPaintingIngredientSymbol::m_categoryName offset mismatch");
static_assert(offsetof(C_ShieldPaintingIngredientSymbol, m_normalTexture) == 0x50,
              "C_ShieldPaintingIngredientSymbol::m_normalTexture offset mismatch");
static_assert(sizeof(C_ShieldPaintingIngredientSymbol) == 0x60,
              "C_ShieldPaintingIngredientSymbol size mismatch");

} // namespace wh::entitymodule
