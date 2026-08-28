#pragma once
#include <cstddef>
#include <cstdint>

#include "E_ShieldPaintingIngredientKind.h"
#include "S_ShieldPaintingIngredientUIName.h"

namespace wh::entitymodule {

class I_ShieldPaintingIngredient {
public:
    virtual ~I_ShieldPaintingIngredient(); // [0]
    virtual const CryStringT<char>& unk_01() const = 0; // [1]
    virtual const CryStringT<char>& unk_02() const = 0; // [2]
    virtual const S_ShieldPaintingIngredientUIName& GetUIName() const = 0; // [3]
    virtual std::int32_t unk_04() const = 0; // [4]
    virtual bool unk_05() const = 0; // [5]
    virtual E_ShieldPaintingIngredientKind GetKind() const = 0; // [6]
    virtual std::int32_t GetCategoryId() const = 0; // [7]
};

static_assert(sizeof(I_ShieldPaintingIngredient) == 0x08,
              "I_ShieldPaintingIngredient size mismatch");

} // namespace wh::entitymodule
