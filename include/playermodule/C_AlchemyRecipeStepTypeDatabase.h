#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "C_AlchemyRecipeStepType.h"

namespace wh::playermodule {

using C_AlchemyRecipeStepTypeDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<C_AlchemyRecipeStepType>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<C_AlchemyRecipeStepType>>;

class C_AlchemyRecipeStepTypeDatabase : public C_AlchemyRecipeStepTypeDatabaseBase {
public:
    ~C_AlchemyRecipeStepTypeDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_AlchemyRecipeStepTypeDatabase) == 0x78,
              "C_AlchemyRecipeStepTypeDatabase size mismatch");

} // namespace wh::playermodule
