#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "S_ItemCategory.h"

namespace wh::entitymodule {

using C_ItemCategoryDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<S_ItemCategory, std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_ItemCategory>>;

class C_ItemCategoryDatabase : public C_ItemCategoryDatabaseBase {
public:
    ~C_ItemCategoryDatabase() override;           // [0] 0x181EE6AE0
    std::int32_t unk_01() const override;         // [1] returns 4
    bool RebuildIndices() override;               // [16] 0x181EE7550
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ItemCategoryDatabase) == 0x78,
              "C_ItemCategoryDatabase size mismatch");

} // namespace wh::entitymodule
