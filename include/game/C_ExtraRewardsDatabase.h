#pragma once
#include <cstddef>
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "C_ExtraRewardData.h"

namespace wh::game {

class C_ExtraRewardsDatabase
    : public wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<C_ExtraRewardData>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<C_ExtraRewardData>> {
public:
    ~C_ExtraRewardsDatabase() override;                       // [0] 0x1839C9AD8
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)    // [18..20]
};

static_assert(sizeof(C_ExtraRewardsDatabase) == 0x78,
              "C_ExtraRewardsDatabase size mismatch");

}  // namespace wh::game
