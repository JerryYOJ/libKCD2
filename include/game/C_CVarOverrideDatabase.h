#pragma once
#include <cstddef>
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "C_CVarOverrideData.h"

namespace wh::game {

class C_CVarOverrideDatabase
    : public wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<C_CVarOverrideData>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<C_CVarOverrideData>> {
public:
    ~C_CVarOverrideDatabase() override;                       // [0] 0x1839BACCC
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)    // [18..20]
};

static_assert(sizeof(C_CVarOverrideDatabase) == 0x78,
              "C_CVarOverrideDatabase size mismatch");

}  // namespace wh::game
