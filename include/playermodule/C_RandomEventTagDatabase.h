#pragma once
#include <cstddef>
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTableDatabase.h"
#include "S_RandomEventTag.h"
#include "S_RandomEventTagDBData.h"
#include "rttr/rttr_enable.h"

namespace wh::playermodule {

using C_RandomEventTagDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTableDatabase<
            S_RandomEventTag,
            S_RandomEventTagDBData>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<
            S_RandomEventTag>>;

class C_RandomEventTagDatabase : public C_RandomEventTagDatabaseBase {
public:
    ~C_RandomEventTagDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_RandomEventTagDatabase) == 0x98,
              "C_RandomEventTagDatabase size mismatch");

} // namespace wh::playermodule
