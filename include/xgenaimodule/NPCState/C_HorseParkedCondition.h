#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Condition.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_HorseParkedCondition : I_Condition
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x18, 9-slot vtable.
// -----------------------------------------------
// Negate is the only RTTR member. +0x10..+0x17 is an unknown region.

namespace wh::xgenaimodule::NPCState {

class C_HorseParkedCondition : public I_Condition {
public:
    ~C_HorseParkedCondition() override;
    I_Condition* unk_01() override;
    bool unk_02(void* arg) override;
    bool unk_03(void* arg) override;
    bool unk_04(void* arg) override;
    std::uint16_t unk_05() override;
    RTTR_ENABLE(I_Condition)
    bool m_negate;                                        // +0x08 RTTR "Negate"
    std::uint8_t _pad09[7];                               // +0x09
    std::uint8_t m_unknown10[8];                          // +0x10
};

static_assert(offsetof(C_HorseParkedCondition, m_negate) == 0x08,
              "C_HorseParkedCondition::m_negate offset mismatch");
static_assert(sizeof(C_HorseParkedCondition) == 0x18,
              "C_HorseParkedCondition size mismatch");

}  // namespace wh::xgenaimodule::NPCState
