#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../../databasemodule/C_ObjectTreeDatabase.h"
#include "../../rttr/rttr_enable.h"
#include "C_ClothingHidingGroup.h"

namespace wh::entitymodule::clothing {

using C_ClothingHidingGroupDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<
            std::shared_ptr<C_ClothingHidingGroup>,
            std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<
            std::shared_ptr<C_ClothingHidingGroup>>>;

class C_ClothingHidingGroupDatabase
    : public C_ClothingHidingGroupDatabaseBase {
public:
    ~C_ClothingHidingGroupDatabase() override;    // [0] 0x1829170A0
    std::int32_t unk_01() const override;          // [1] returns 4
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ClothingHidingGroupDatabase) == 0x78,
              "C_ClothingHidingGroupDatabase size mismatch");

} // namespace wh::entitymodule::clothing
