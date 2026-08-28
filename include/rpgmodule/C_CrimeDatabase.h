#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "S_Crime.h"

namespace wh::rpgmodule {

using C_CrimeDatabaseBase = wh::databasemodule::C_ObjectTreeDatabase<S_Crime>;

class C_CrimeDatabase : public C_CrimeDatabaseBase {
public:
    ~C_CrimeDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_CrimeDatabase) == 0x78,
              "C_CrimeDatabase size mismatch");

} // namespace wh::rpgmodule
