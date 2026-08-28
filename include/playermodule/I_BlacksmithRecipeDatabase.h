#pragma once
#include <cstddef>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::rpgmodule { class I_Soul; }

namespace wh::playermodule {

class I_BlacksmithRecipe;

class I_BlacksmithRecipeDatabase {
public:
    virtual std::vector<I_BlacksmithRecipe*> GetRecipes() const = 0; // [0]
    virtual std::vector<I_BlacksmithRecipe*> GetAvailableRecipes(
        wh::rpgmodule::I_Soul* soul) const = 0;                 // [1]
    virtual I_BlacksmithRecipe* FindRecipe(
        const CryStringT<char>& id) const = 0;                  // [2]
};

static_assert(sizeof(I_BlacksmithRecipeDatabase) == 0x08,
              "I_BlacksmithRecipeDatabase size mismatch");

} // namespace wh::playermodule
