#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "C_AlchemyPotionBase.h"

namespace wh::playermodule {

using C_AlchemyPotionBaseDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<C_AlchemyPotionBase>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<C_AlchemyPotionBase>>;

class C_AlchemyPotionBaseDatabase : public C_AlchemyPotionBaseDatabaseBase {
public:
    ~C_AlchemyPotionBaseDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_AlchemyPotionBaseDatabase) == 0x78,
              "C_AlchemyPotionBaseDatabase size mismatch");

} // namespace wh::playermodule
