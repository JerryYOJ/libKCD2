#pragma once
#include <cstddef>
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "C_LevelData.h"

namespace wh::game {

class C_LevelDatabase
    : public wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<C_LevelData>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<C_LevelData>> {
public:
    ~C_LevelDatabase() override;                              // [0] 0x1839F7478
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)    // [18..20]
};

static_assert(sizeof(C_LevelDatabase) == 0x78,
              "C_LevelDatabase size mismatch");

}  // namespace wh::game
