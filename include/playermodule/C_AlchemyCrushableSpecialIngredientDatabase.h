#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "C_AlchemyCrushableSpecialIngredient.h"

namespace wh::playermodule {

using C_AlchemyCrushableSpecialIngredientDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<C_AlchemyCrushableSpecialIngredient>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<C_AlchemyCrushableSpecialIngredient>>;

class C_AlchemyCrushableSpecialIngredientDatabase : public C_AlchemyCrushableSpecialIngredientDatabaseBase {
public:
    ~C_AlchemyCrushableSpecialIngredientDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_AlchemyCrushableSpecialIngredientDatabase) == 0x78,
              "C_AlchemyCrushableSpecialIngredientDatabase size mismatch");

} // namespace wh::playermodule
