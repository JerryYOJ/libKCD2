#pragma once
#include <cstddef>
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "C_LevelSwitchData.h"

namespace wh::game {

class C_LevelSwitchDatabase
    : public wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<C_LevelSwitchData>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<C_LevelSwitchData>> {
public:
    ~C_LevelSwitchDatabase() override;                        // [0] 0x1839F75D0
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)    // [18..20]
};

static_assert(sizeof(C_LevelSwitchDatabase) == 0x78,
              "C_LevelSwitchDatabase size mismatch");

}  // namespace wh::game
