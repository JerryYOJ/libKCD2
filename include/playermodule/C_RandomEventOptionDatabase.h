#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "S_RandomEventOption.h"

namespace wh::playermodule {

using C_RandomEventOptionDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<S_RandomEventOption>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_RandomEventOption>>;

class C_RandomEventOptionDatabase : public C_RandomEventOptionDatabaseBase {
public:
    ~C_RandomEventOptionDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_RandomEventOptionDatabase) == 0x78,
              "C_RandomEventOptionDatabase size mismatch");

} // namespace wh::playermodule
