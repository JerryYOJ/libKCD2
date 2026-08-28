#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Condition.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_HorseUsageCondition : I_Condition
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10, 9-slot vtable.
// -----------------------------------------------

namespace wh::xgenaimodule::NPCState {

class C_HorseUsageCondition : public I_Condition {
public:
    ~C_HorseUsageCondition() override;
    I_Condition* unk_01() override;
    bool unk_02(void* arg) override;
    bool unk_03(void* arg) override;
    bool unk_04(void* arg) override;
    std::uint16_t unk_05() override;
    RTTR_ENABLE(I_Condition)
    bool m_requiresEmpty;                                 // +0x08 RTTR "RequiresEmpty"
    std::uint8_t _pad09[7];                               // +0x09
};

static_assert(offsetof(C_HorseUsageCondition, m_requiresEmpty) == 0x08,
              "C_HorseUsageCondition::m_requiresEmpty offset mismatch");
static_assert(sizeof(C_HorseUsageCondition) == 0x10,
              "C_HorseUsageCondition size mismatch");

}  // namespace wh::xgenaimodule::NPCState
