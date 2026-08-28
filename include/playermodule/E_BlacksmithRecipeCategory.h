#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

enum class E_BlacksmithRecipeCategory : std::int32_t {
    ShortSword = 0,
    LongSword  = 1,
    Axe        = 2,
    Other      = 3,
};
static_assert(sizeof(E_BlacksmithRecipeCategory) == 4, "E_BlacksmithRecipeCategory size mismatch");

}  // namespace wh::playermodule
