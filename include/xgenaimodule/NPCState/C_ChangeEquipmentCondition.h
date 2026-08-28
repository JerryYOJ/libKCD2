#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Condition.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_ChangeEquipmentCondition : I_Condition
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10; vtable 0x183BD2E68 (9 slots).
// -----------------------------------------------

namespace wh::xgenaimodule::NPCState {

class C_ChangeEquipmentCondition : public I_Condition {
public:
    ~C_ChangeEquipmentCondition() override;               // [0]
    I_Condition* unk_01() override;                       // [1] 0x1816038E8 clone
    bool unk_02(void* arg) override;                      // [2] 0x1806C94A4
    bool unk_03(void* arg) override;                      // [3] 0x18041A6A0 true
    bool unk_04(void* arg) override;                      // [4] 0x18041A6A0 true
    std::uint16_t unk_05() override;                      // [5] 0x1819DF570 writes 0x104
    RTTR_ENABLE(I_Condition)                              // [6..8]
    bool m_requiredDefault;                               // +0x08 RTTR "RequiredDefault"
    std::uint8_t _pad09[7];                               // +0x09
};

static_assert(offsetof(C_ChangeEquipmentCondition, m_requiredDefault) == 0x08,
              "C_ChangeEquipmentCondition::m_requiredDefault offset mismatch");
static_assert(sizeof(C_ChangeEquipmentCondition) == 0x10,
              "C_ChangeEquipmentCondition size mismatch");

}  // namespace wh::xgenaimodule::NPCState
