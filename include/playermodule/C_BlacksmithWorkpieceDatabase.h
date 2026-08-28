#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "C_BlacksmithWorkpiece.h"

namespace wh::playermodule {

using C_BlacksmithWorkpieceDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<C_BlacksmithWorkpiece>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<C_BlacksmithWorkpiece>>;

class C_BlacksmithWorkpieceDatabase : public C_BlacksmithWorkpieceDatabaseBase {
public:
    ~C_BlacksmithWorkpieceDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_BlacksmithWorkpieceDatabase) == 0x78,
              "C_BlacksmithWorkpieceDatabase size mismatch");

} // namespace wh::playermodule
