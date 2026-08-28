#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "S_EquipmentPresetFilter.h"
#include "S_ResolvedEquipmentPresetFilter.h"

namespace wh::entitymodule {

using C_EquipmentPresetFilterDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabase<
        S_EquipmentPresetFilter,
        std::vector>;

class C_EquipmentPresetFilterDatabase
    : public C_EquipmentPresetFilterDatabaseBase {
public:
    ~C_EquipmentPresetFilterDatabase() override; // [0] 0x182A1DD30
    std::int32_t unk_01() const override;         // [1] returns 4
    bool unk_11() override;                       // [11] returns true
    void CollectDependencies(
        std::vector<wh::databasemodule::C_ObjectDatabaseBase*>& dependencies) override; // [12]
    bool RebuildIndices() override;               // [16] 0x1819DDBB4
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]

    std::unordered_map<
        CryStringT<char>,
        S_ResolvedEquipmentPresetFilter> m_filtersByName; // +0x78
};

static_assert(offsetof(C_EquipmentPresetFilterDatabase, m_filtersByName) == 0x78,
              "C_EquipmentPresetFilterDatabase::m_filtersByName offset mismatch");
static_assert(sizeof(C_EquipmentPresetFilterDatabase) == 0xB8,
              "C_EquipmentPresetFilterDatabase size mismatch");

} // namespace wh::entitymodule
