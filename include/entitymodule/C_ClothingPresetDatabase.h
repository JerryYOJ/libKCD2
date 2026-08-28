#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "S_ClothingPreset.h"

namespace wh::entitymodule {

using C_ClothingPresetDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<S_ClothingPreset, std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_ClothingPreset>>;

class C_ClothingPresetDatabase : public C_ClothingPresetDatabaseBase {
public:
    ~C_ClothingPresetDatabase() override;          // [0] 0x1829A81CC
    std::int32_t unk_01() const override;           // [1] returns 4
    bool unk_11() override;                         // [11] returns true
    bool RebuildIndices() override;                 // [16] 0x180F65004
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]

    std::vector<std::pair<CryStringT<char>, S_ClothingPreset*>>
        m_presetsByName;                            // +0x78
};

static_assert(offsetof(C_ClothingPresetDatabase, m_presetsByName) == 0x78,
              "C_ClothingPresetDatabase::m_presetsByName offset mismatch");
static_assert(sizeof(C_ClothingPresetDatabase) == 0x90,
              "C_ClothingPresetDatabase size mismatch");

} // namespace wh::entitymodule
