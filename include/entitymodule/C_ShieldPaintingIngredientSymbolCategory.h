#pragma once
#include <cstddef>
#include <cstdint>

#include "../rttr/rttr_enable.h"
#include "C_ShieldPaintingIngredientBase.h"

namespace wh::entitymodule {

class C_ShieldPaintingIngredientSymbolCategory
    : public C_ShieldPaintingIngredientBase {
public:
    E_ShieldPaintingIngredientKind GetKind() const override; // [6] returns SymbolCategory
    std::int32_t GetCategoryId() const override; // [7] returns -1
    RTTR_ENABLE(C_ShieldPaintingIngredientBase) // [8..10]
};

static_assert(sizeof(C_ShieldPaintingIngredientSymbolCategory) == 0x20,
              "C_ShieldPaintingIngredientSymbolCategory size mismatch");

} // namespace wh::entitymodule
