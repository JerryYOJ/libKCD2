#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "S_RandomEventOptionSet.h"

namespace wh::playermodule {

using C_RandomEventOptionSetDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<S_RandomEventOptionSet>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_RandomEventOptionSet>>;

class C_RandomEventOptionSetDatabase : public C_RandomEventOptionSetDatabaseBase {
public:
    ~C_RandomEventOptionSetDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_RandomEventOptionSetDatabase) == 0x78,
              "C_RandomEventOptionSetDatabase size mismatch");

} // namespace wh::playermodule
