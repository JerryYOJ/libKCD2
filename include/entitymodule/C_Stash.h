#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include "C_LockBase.h"
#include "I_InventoryListener.h"
#include "S_StashValueWatcher.h"
#include "../framework/CryDeferrable.h"
#include "../framework/I_ScheduleUpdatable.h"

namespace wh::entitymodule {

class C_Inventory;

class C_Stash
    : public C_LockBase
    , public wh::framework::I_ScheduleUpdatable
    , public I_InventoryListener
    , public UnsafeOp::CryDeferrable<0> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Stash;

    ~C_Stash() override;                                            // [0] 0x180965790
    void ProcessEvent(SEntityEvent& event) override;                // [1] 0x181128474
    void GetMemoryUsage(ICrySizer* sizer) const override;           // [6] 0x182ABC738
    bool Init(Offsets::IGameObject* gameObject) override;           // [7] 0x180A2E5C4
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11] 0x1827D22E8
    bool GetEntityPoolSignature(TSerialize signature) override;    // [13] 0x182ABB710
    void Release() override;                                       // [14] 0x1809657D4
    void FullSerialize(TSerialize serializer) override;            // [15] 0x182ABA6E4
    bool _vf17() override;                                         // [17] 0x182ABF348
    const char* GetExtensionName() const override;                  // [29] 0x180705D40
    bool CanUnlockWithItemClass(const CryGUID& itemClassId) const override; // [30] 0x182AC08E8

    RTTR_ENABLE() // [31..33]

    void ScheduleUpdate(std::int32_t value) override;               // schedule [0] 0x1808F2F30
    void InventoryListenerUnk0(C_Item* item,
                               std::uint32_t amount) override;       // listener [0] 0x1810F4698
    void InventoryListenerUnk2(S_ItemClass* itemClass,
                               std::uint32_t amount,
                               framework::WUID itemWuid) override;   // listener [2] 0x181225404

    C_Inventory* GetInventory() const { return m_pInventory; }       // 0x1807E3D60, RTTR Inventory

    wh::shared::C_Signal<> m_signal80;                 // +0x80, template payload/role OPEN
    wh::shared::C_Signal<> m_signal90;                 // +0x90, template payload/role OPEN
    S_StashValueWatcher m_valueWatcher;                // +0xA0
    C_Inventory* m_pInventory;                         // +0xB8, borrowed
    CryStringT<char> m_inventoryPreset;                // +0xC0
    std::uint64_t m_restockStateC8;                    // +0xC8, role/name OPEN
    std::int32_t m_scheduleStateD0;                    // +0xD0, initialized to -1
    std::uint16_t m_restockPeriodDays;                 // +0xD4
    std::uint16_t m_destockPeriodDays;                 // +0xD6
    std::uint32_t m_stashEntityId;                     // +0xD8
    std::uint32_t _padDC;                              // +0xDC
    std::unordered_map<CryGUID, std::int32_t>
        m_lootItemCounts;                              // +0xE0, class GUID -> stack-count snapshot/delta
    std::uint8_t m_flag120;                            // +0x120, role OPEN
    std::uint8_t _pad121[7];                           // +0x121
};
static_assert(sizeof(C_Stash) == 0x128, "C_Stash must be 0x128");
static_assert(offsetof(C_Stash, m_signal80) == 0x80,
              "first Stash signal must be at 0x80");
static_assert(offsetof(C_Stash, m_pInventory) == 0xB8,
              "Stash inventory pointer must be at 0xB8");
static_assert(offsetof(C_Stash, m_lootItemCounts) == 0xE0,
              "Stash loot-count map must be at 0xE0");
static_assert(offsetof(C_Stash, m_flag120) == 0x120,
              "Stash tail flag must be at 0x120");

}  // namespace wh::entitymodule
