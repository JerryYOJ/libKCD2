#pragma once
#include <cstddef>
#include <cstdint>
#include "E_DataSource.h"
#include "I_Condition.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_CombatAutomationsCondition : I_Condition
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10, 9-slot vtable.
// -----------------------------------------------

namespace wh::xgenaimodule::NPCState {

class C_CombatAutomationsCondition : public I_Condition {
public:
    ~C_CombatAutomationsCondition() override;
    I_Condition* unk_01() override;
    bool unk_02(void* arg) override;
    bool unk_03(void* arg) override;
    bool unk_04(void* arg) override;
    std::uint16_t unk_05() override;
    RTTR_ENABLE(I_Condition)
    E_DataSource m_dataSource;                            // +0x08 RTTR "DataSource"
    std::uint8_t _pad0C[4];                               // +0x0C
};

static_assert(offsetof(C_CombatAutomationsCondition, m_dataSource) == 0x08,
              "C_CombatAutomationsCondition::m_dataSource offset mismatch");
static_assert(sizeof(C_CombatAutomationsCondition) == 0x10,
              "C_CombatAutomationsCondition size mismatch");

}  // namespace wh::xgenaimodule::NPCState
