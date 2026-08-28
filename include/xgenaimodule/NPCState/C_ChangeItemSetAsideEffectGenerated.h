#pragma once
#include <cstddef>
#include <cstdint>
#include "../E_HandType.h"
#include "C_EffectBase.h"
#include "S_EffectObjectSource.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeItemSetAsideEffectGenerated : public C_EffectBase {
public:
    ~C_ChangeItemSetAsideEffectGenerated() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    bool unk_04() override;
    bool unk_05() override;
    bool unk_08() override;
    bool unk_09() override;
    RTTR_ENABLE(C_EffectBase)

    S_EffectObjectSource m_itemRuntimeInitSource;            // +0x10 RTTR "ItemRuntimeInitSource"
    S_EffectObjectSource m_slotRuntimeInitSource;            // +0x30 RTTR "SlotRuntimeInitSource"
    wh::xgenaimodule::E_HandType::Type m_handRuntimeInitSource; // +0x50 RTTR "HandRuntimeInitSource"
    bool m_allowItemInitFromHand;                            // +0x54 RTTR "AllowItemInitFromHand"
    bool m_allowItemInitFromDataSourceState;                 // +0x55 RTTR "AllowItemInitFromDataSourceState"
    bool m_allowFindingSourceSlotOnly;                       // +0x56 RTTR "AllowFindingSourceSlotOnly"
    std::uint8_t m_unknown57[0x19];                          // +0x57
};

static_assert(offsetof(C_ChangeItemSetAsideEffectGenerated, m_itemRuntimeInitSource) == 0x10,
              "C_ChangeItemSetAsideEffectGenerated::m_itemRuntimeInitSource offset mismatch");
static_assert(offsetof(C_ChangeItemSetAsideEffectGenerated, m_slotRuntimeInitSource) == 0x30,
              "C_ChangeItemSetAsideEffectGenerated::m_slotRuntimeInitSource offset mismatch");
static_assert(offsetof(C_ChangeItemSetAsideEffectGenerated, m_handRuntimeInitSource) == 0x50,
              "C_ChangeItemSetAsideEffectGenerated::m_handRuntimeInitSource offset mismatch");
static_assert(sizeof(C_ChangeItemSetAsideEffectGenerated) == 0x70,
              "C_ChangeItemSetAsideEffectGenerated size mismatch");

}  // namespace wh::xgenaimodule::NPCState
