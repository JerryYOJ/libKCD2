#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "S_ClothingConfig.h"

namespace wh::entitymodule {

using C_ClothingConfigDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<S_ClothingConfig, std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_ClothingConfig>>;

class C_ClothingConfigDatabase : public C_ClothingConfigDatabaseBase {
public:
    ~C_ClothingConfigDatabase() override;        // [0] 0x182917004
    std::int32_t unk_01() const override;         // [1] returns 4
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ClothingConfigDatabase) == 0x78,
              "C_ClothingConfigDatabase size mismatch");

} // namespace wh::entitymodule
