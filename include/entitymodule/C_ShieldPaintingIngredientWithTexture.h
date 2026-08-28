#pragma once
#include <cstddef>

#include "../rttr/rttr_enable.h"
#include "C_ShieldPaintingIngredientBase.h"

struct ITexture;

namespace wh::entitymodule {

class C_ShieldPaintingIngredientWithTexture
    : public C_ShieldPaintingIngredientBase {
public:
    ~C_ShieldPaintingIngredientWithTexture() override; // [0] 0x181EB2B40
    RTTR_ENABLE(C_ShieldPaintingIngredientBase) // [8..10]

    CryStringT<char> m_texturePath; // +0x20 RTTR "TexturePath"
    ITexture* m_texture;            // +0x28 EF_LoadTexture result
};

static_assert(offsetof(C_ShieldPaintingIngredientWithTexture, m_texturePath) == 0x20,
              "C_ShieldPaintingIngredientWithTexture::m_texturePath offset mismatch");
static_assert(offsetof(C_ShieldPaintingIngredientWithTexture, m_texture) == 0x28,
              "C_ShieldPaintingIngredientWithTexture::m_texture offset mismatch");
static_assert(sizeof(C_ShieldPaintingIngredientWithTexture) == 0x30,
              "C_ShieldPaintingIngredientWithTexture size mismatch");

} // namespace wh::entitymodule
