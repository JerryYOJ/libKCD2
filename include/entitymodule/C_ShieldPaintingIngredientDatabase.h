#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class I_ShieldPaintingIngredient;

using C_ShieldPaintingIngredientDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<
            std::shared_ptr<I_ShieldPaintingIngredient>,
            std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<
            std::shared_ptr<I_ShieldPaintingIngredient>>>;

class C_ShieldPaintingIngredientDatabase
    : public C_ShieldPaintingIngredientDatabaseBase {
public:
    ~C_ShieldPaintingIngredientDatabase() override; // [0] 0x181EB2950
    std::int32_t unk_01() const override;            // [1] returns 4
    bool RebuildIndices() override;                  // [16] 0x181EB3630
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ShieldPaintingIngredientDatabase) == 0x78,
              "C_ShieldPaintingIngredientDatabase size mismatch");

} // namespace wh::entitymodule
