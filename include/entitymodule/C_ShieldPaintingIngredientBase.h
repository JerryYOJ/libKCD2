#pragma once
#include <cstddef>
#include <cstdint>

#include "../rttr/rttr_enable.h"
#include "I_ShieldPaintingIngredient.h"

namespace wh::entitymodule {

class C_ShieldPaintingIngredientBase : public I_ShieldPaintingIngredient {
public:
    ~C_ShieldPaintingIngredientBase() override; // [0] 0x181EB2A40
    const CryStringT<char>& unk_01() const override; // [1] 0x181A71D30
    const CryStringT<char>& unk_02() const override; // [2] 0x181A71D30
    const S_ShieldPaintingIngredientUIName& GetUIName() const override; // [3] 0x181A72EC0
    std::int32_t unk_04() const override; // [4] 0x181A72850
    bool unk_05() const override; // [5] 0x181A7E140
    RTTR_ENABLE(I_ShieldPaintingIngredient) // [8..10]

    CryStringT<char> m_name;                   // +0x08 RTTR "Name"
    S_ShieldPaintingIngredientUIName m_uiName; // +0x10 RTTR "UIName"
};

static_assert(offsetof(C_ShieldPaintingIngredientBase, m_name) == 0x08,
              "C_ShieldPaintingIngredientBase::m_name offset mismatch");
static_assert(offsetof(C_ShieldPaintingIngredientBase, m_uiName) == 0x10,
              "C_ShieldPaintingIngredientBase::m_uiName offset mismatch");
static_assert(sizeof(C_ShieldPaintingIngredientBase) == 0x20,
              "C_ShieldPaintingIngredientBase size mismatch");

} // namespace wh::entitymodule
