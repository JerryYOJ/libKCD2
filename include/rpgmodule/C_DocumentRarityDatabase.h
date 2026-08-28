#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "S_DocumentRarity.h"

namespace wh::rpgmodule {

using C_DocumentRarityDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<S_DocumentRarity>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_DocumentRarity>>;

class C_DocumentRarityDatabase : public C_DocumentRarityDatabaseBase {
public:
    ~C_DocumentRarityDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_DocumentRarityDatabase) == 0x78,
              "C_DocumentRarityDatabase size mismatch");

} // namespace wh::rpgmodule
