#pragma once
#include <cstdint>

namespace wh::entitymodule {

enum class E_ShieldPaintingIngredientKind : std::uint8_t {
    Pattern = 0,
    Symbol = 1,
    SymbolCategory = 2,
    Color = 3,
};

static_assert(sizeof(E_ShieldPaintingIngredientKind) == 1,
              "E_ShieldPaintingIngredientKind size mismatch");

} // namespace wh::entitymodule
