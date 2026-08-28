#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "S_CatWaypointRecord.h"

namespace wh::entitymodule {

using C_CatWaypointDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<S_CatWaypointRecord, std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_CatWaypointRecord>>;

class C_CatWaypointDatabase : public C_CatWaypointDatabaseBase {
public:
    ~C_CatWaypointDatabase() override;           // [0] 0x1828F0B1C
    std::int32_t unk_01() const override;         // [1] returns 14
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_CatWaypointDatabase) == 0x78,
              "C_CatWaypointDatabase size mismatch");

} // namespace wh::entitymodule
