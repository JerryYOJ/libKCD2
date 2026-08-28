#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>

#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "C_InventoryPreset.h"

namespace wh::entitymodule {

using C_InventoryPresetDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabase<
        std::shared_ptr<C_InventoryPreset>,
        std::vector>;

class C_InventoryPresetDatabase : public C_InventoryPresetDatabaseBase {
public:
    ~C_InventoryPresetDatabase() override;         // [0] 0x182A1DE88
    std::int32_t unk_01() const override;           // [1] returns 4
    bool unk_11() override;                         // [11] returns true
    void CollectDependencies(
        std::vector<wh::databasemodule::C_ObjectDatabaseBase*>& dependencies) override; // [12]
    bool RebuildIndices() override;                 // [16] 0x1813EC20C
    void OnLoaded() override;                       // [17] 0x181364F50
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]

    std::unordered_map<CryStringT<char>, C_InventoryPreset*>
        m_presetsByName;                            // +0x78
};

static_assert(offsetof(C_InventoryPresetDatabase, m_presetsByName) == 0x78,
              "C_InventoryPresetDatabase::m_presetsByName offset mismatch");
static_assert(sizeof(C_InventoryPresetDatabase) == 0xB8,
              "C_InventoryPresetDatabase size mismatch");

} // namespace wh::entitymodule
