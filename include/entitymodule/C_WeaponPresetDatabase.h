#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "C_WeaponPreset.h"

namespace wh::entitymodule {

using C_WeaponPresetDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<C_WeaponPreset, std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<C_WeaponPreset>>;

class C_WeaponPresetDatabase : public C_WeaponPresetDatabaseBase {
public:
    ~C_WeaponPresetDatabase() override;            // [0] 0x182ACB540
    std::int32_t unk_01() const override;           // [1] returns 4
    bool unk_11() override;                         // [11] returns true
    bool RebuildIndices() override;                 // [16] 0x180ED0A68
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]

    std::vector<std::pair<CryStringT<char>, C_WeaponPreset*>>
        m_presetsByName;                            // +0x78
};

static_assert(offsetof(C_WeaponPresetDatabase, m_presetsByName) == 0x78,
              "C_WeaponPresetDatabase::m_presetsByName offset mismatch");
static_assert(sizeof(C_WeaponPresetDatabase) == 0x90,
              "C_WeaponPresetDatabase size mismatch");

} // namespace wh::entitymodule
