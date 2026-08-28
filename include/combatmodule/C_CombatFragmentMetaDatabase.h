#pragma once
#include <cstddef>
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "C_CombatFragmentMetaData.h"

namespace wh::combatmodule {

class C_CombatFragmentMetaDatabase
    : public wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<C_CombatFragmentMetaData>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<
              C_CombatFragmentMetaData>> {
public:
    ~C_CombatFragmentMetaDatabase() override;                   // [0] 0x1827A4E38
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)      // [18..20]
};

static_assert(sizeof(C_CombatFragmentMetaDatabase) == 0x78,
              "C_CombatFragmentMetaDatabase size mismatch");

}  // namespace wh::combatmodule
