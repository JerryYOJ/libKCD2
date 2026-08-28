#pragma once
#include <cstddef>
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTableDatabase.h"
#include "S_ForgeWardrobeItemFilter.h"
#include "S_ForgeWardrobeItemFilterDBData.h"
#include "rttr/rttr_enable.h"

namespace wh::playermodule {

using C_ForgeWardrobeItemFilterDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTableDatabase<
            S_ForgeWardrobeItemFilter,
            S_ForgeWardrobeItemFilterDBData>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<
            S_ForgeWardrobeItemFilter>>;

class C_ForgeWardrobeItemFilterDatabase
    : public C_ForgeWardrobeItemFilterDatabaseBase {
public:
    ~C_ForgeWardrobeItemFilterDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ForgeWardrobeItemFilterDatabase) == 0x98,
              "C_ForgeWardrobeItemFilterDatabase size mismatch");

} // namespace wh::playermodule
