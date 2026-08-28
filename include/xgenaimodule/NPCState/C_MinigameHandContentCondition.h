#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Condition.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_MinigameHandContentCondition : I_Condition
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x20, 9-slot vtable.
// -----------------------------------------------
// No RTTR members. Extra 0x18 bytes after I_Condition are unknown.

namespace wh::xgenaimodule::NPCState {

class C_MinigameHandContentCondition : public I_Condition {
public:
    ~C_MinigameHandContentCondition() override;
    I_Condition* unk_01() override;
    bool unk_02(void* arg) override;
    bool unk_03(void* arg) override;
    bool unk_04(void* arg) override;
    std::uint16_t unk_05() override;
    RTTR_ENABLE(I_Condition)
    std::uint8_t m_unknown08[0x18];                       // +0x08
};

static_assert(offsetof(C_MinigameHandContentCondition, m_unknown08) == 0x08,
              "C_MinigameHandContentCondition::m_unknown08 offset mismatch");
static_assert(sizeof(C_MinigameHandContentCondition) == 0x20,
              "C_MinigameHandContentCondition size mismatch");

}  // namespace wh::xgenaimodule::NPCState
