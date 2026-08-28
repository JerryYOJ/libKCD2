#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "C_SkirmishEventTypeData.h"

namespace wh::rpgmodule {

using C_SkirmishEventDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<C_SkirmishEventTypeData>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<C_SkirmishEventTypeData>>;

class C_SkirmishEventDatabase : public C_SkirmishEventDatabaseBase {
public:
    ~C_SkirmishEventDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_SkirmishEventDatabase) == 0x78,
              "C_SkirmishEventDatabase size mismatch");

} // namespace wh::rpgmodule
