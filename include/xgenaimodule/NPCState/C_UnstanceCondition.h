#pragma once

#include <cstddef>
#include <cstdint>

#include "C_UnstanceConditionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_UnstanceCondition : public C_UnstanceConditionBase {
public:
    C_UnstanceCondition();                                               // 0x181694344
    ~C_UnstanceCondition() override;                                     // [0]
    I_Condition* unk_01() override;
    bool unk_02(void* arg) override;
    bool unk_03(void* arg) override;
    bool unk_04(void* arg) override;
    std::uint16_t unk_05() override;
    RTTR_ENABLE(C_UnstanceConditionBase)                                 // [6..8], vtable 0x183A2EDB0

    std::uint32_t m_requiredUnstance;                                    // +0x08 RTTR "RequiredUnstance"
    std::uint8_t m_padding0C[4];                                         // +0x0C
};

static_assert(offsetof(C_UnstanceCondition, m_requiredUnstance) == 0x08,
              "C_UnstanceCondition::m_requiredUnstance offset mismatch");
static_assert(sizeof(C_UnstanceCondition) == 0x10,
              "C_UnstanceCondition size mismatch");

} // namespace wh::xgenaimodule::NPCState
