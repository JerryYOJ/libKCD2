#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "C_PlayerData.h"

namespace wh::playermodule {

using C_PlayerDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<C_PlayerData>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<C_PlayerData>>;

class C_PlayerDatabase : public C_PlayerDatabaseBase {
public:
    ~C_PlayerDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_PlayerDatabase) == 0x78,
              "C_PlayerDatabase size mismatch");

} // namespace wh::playermodule
