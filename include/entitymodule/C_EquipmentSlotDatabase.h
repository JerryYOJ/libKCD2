#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include <vector>

#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rpgmodule/E_BloodZoneId.h"
#include "../rttr/rttr_enable.h"
#include "C_EquipmentSlot.h"

namespace wh::entitymodule {

using C_EquipmentSlotDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabase<C_EquipmentSlot, std::vector>;

class C_EquipmentSlotDatabase : public C_EquipmentSlotDatabaseBase {
public:
    ~C_EquipmentSlotDatabase() override;           // [0] 0x1829FD680
    std::int32_t unk_01() const override;           // [1] returns 4
    bool unk_11() override;                         // [11] returns true
    void CollectDependencies(
        std::vector<wh::databasemodule::C_ObjectDatabaseBase*>& dependencies) override; // [12]
    bool RebuildIndices() override;                 // [16] 0x18127ED50
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]

    std::map<
        wh::rpgmodule::E_BloodZoneId,
        std::vector<C_EquipmentSlot*>> m_slotsByBloodZone; // +0x78
};

static_assert(offsetof(C_EquipmentSlotDatabase, m_slotsByBloodZone) == 0x78,
              "C_EquipmentSlotDatabase::m_slotsByBloodZone offset mismatch");
static_assert(sizeof(C_EquipmentSlotDatabase) == 0x88,
              "C_EquipmentSlotDatabase size mismatch");

} // namespace wh::entitymodule
