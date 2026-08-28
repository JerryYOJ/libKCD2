#pragma once
#include <cstddef>
#include <vector>
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "C_BlacksmithRecipe.h"
#include "I_BlacksmithRecipeDatabase.h"

namespace wh::playermodule {

using C_BlacksmithRecipeDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<
            C_BlacksmithRecipe,
            std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<
            C_BlacksmithRecipe>>;

class C_BlacksmithRecipeDatabase
    : public C_BlacksmithRecipeDatabaseBase,
      public I_BlacksmithRecipeDatabase {
public:
    ~C_BlacksmithRecipeDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]

    std::vector<I_BlacksmithRecipe*> GetRecipes() const override; // secondary [0]
    std::vector<I_BlacksmithRecipe*> GetAvailableRecipes(
        wh::rpgmodule::I_Soul* soul) const override;             // secondary [1]
    I_BlacksmithRecipe* FindRecipe(
        const CryStringT<char>& id) const override;              // secondary [2]
};

static_assert(sizeof(C_BlacksmithRecipeDatabase) == 0x80,
              "C_BlacksmithRecipeDatabase size mismatch");

} // namespace wh::playermodule
