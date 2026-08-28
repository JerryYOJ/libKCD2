#pragma once
#include <cstddef>
#include <cstdint>
#include "../E_HandType.h"
#include "E_DataSource.h"
#include "I_Condition.h"
#include "S_EffectObjectSource.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_ItemSetAsideConditionGenerated : I_Condition
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x70, 9-slot vtable.
// -----------------------------------------------
// +0x57..+0x6F is an unknown tail after the last RTTR bool.

namespace wh::xgenaimodule::NPCState {

class C_ItemSetAsideConditionGenerated : public I_Condition {
public:
    ~C_ItemSetAsideConditionGenerated() override;
    I_Condition* unk_01() override;
    bool unk_02(void* arg) override;
    bool unk_03(void* arg) override;
    bool unk_04(void* arg) override;
    std::uint16_t unk_05() override;
    RTTR_ENABLE(I_Condition)
    E_DataSource m_dataSource;                            // +0x08 RTTR "DataSource"
    std::uint8_t _pad0C[4];                               // +0x0C
    S_EffectObjectSource m_itemRuntimeInitSource;         // +0x10 RTTR "ItemRuntimeInitSource"
    S_EffectObjectSource m_slotRuntimeInitSource;         // +0x30 RTTR "SlotRuntimeInitSource"
    wh::xgenaimodule::E_HandType::Type m_hand;            // +0x50 RTTR "Hand"
    bool m_allowItemInitFromHand;                         // +0x54 RTTR "AllowItemInitFromHand"
    bool m_allowItemInitFromDataSourceState;              // +0x55 RTTR "AllowItemInitFromDataSourceState"
    bool m_allowFindingSourceSlotOnly;                    // +0x56 RTTR "AllowFindingSourceSlotOnly"
    std::uint8_t m_unknown57[0x19];                       // +0x57
};

static_assert(offsetof(C_ItemSetAsideConditionGenerated, m_dataSource) == 0x08,
              "C_ItemSetAsideConditionGenerated::m_dataSource offset mismatch");
static_assert(offsetof(C_ItemSetAsideConditionGenerated, m_itemRuntimeInitSource) == 0x10,
              "C_ItemSetAsideConditionGenerated::m_itemRuntimeInitSource offset mismatch");
static_assert(offsetof(C_ItemSetAsideConditionGenerated, m_slotRuntimeInitSource) == 0x30,
              "C_ItemSetAsideConditionGenerated::m_slotRuntimeInitSource offset mismatch");
static_assert(offsetof(C_ItemSetAsideConditionGenerated, m_hand) == 0x50,
              "C_ItemSetAsideConditionGenerated::m_hand offset mismatch");
static_assert(sizeof(C_ItemSetAsideConditionGenerated) == 0x70,
              "C_ItemSetAsideConditionGenerated size mismatch");

}  // namespace wh::xgenaimodule::NPCState
