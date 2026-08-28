#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>

#include "../../databasemodule/C_ObjectTreeDatabase.h"
#include "../../databasemodule/C_ObjectTreeDatabaseKeyIndexed.h"
#include "../../rttr/rttr_enable.h"
#include "C_ClothingMaterial.h"

namespace wh::entitymodule::clothing {

using C_ClothingMaterialDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<
            std::shared_ptr<C_ClothingMaterial>,
            std::vector>,
        std::unordered_map<
            CryStringT<char>,
            std::shared_ptr<C_ClothingMaterial>>>;

class C_ClothingMaterialDatabase : public C_ClothingMaterialDatabaseBase {
public:
    ~C_ClothingMaterialDatabase() override;        // [0] 0x18295C088
    std::int32_t unk_01() const override;           // [1] returns 4
    bool unk_11() override;                         // [11] returns true
    bool RebuildIndices() override;                 // [16] 0x180FE2D14
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ClothingMaterialDatabase) == 0xB8,
              "C_ClothingMaterialDatabase size mismatch");

} // namespace wh::entitymodule::clothing
