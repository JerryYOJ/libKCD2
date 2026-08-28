#pragma once

#include <cstddef>

#include "C_UnstanceConditionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_NoUnstanceCondition : public C_UnstanceConditionBase {
public:
    C_NoUnstanceCondition();                                             // 0x1816944B0
    ~C_NoUnstanceCondition() override;                                   // [0]
    I_Condition* unk_01() override;
    bool unk_02(void* arg) override;
    bool unk_03(void* arg) override;
    bool unk_04(void* arg) override;
    std::uint16_t unk_05() override;
    RTTR_ENABLE(C_UnstanceConditionBase)                                 // [6..8], vtable 0x183A44DB0
};

static_assert(sizeof(C_NoUnstanceCondition) == 0x08,
              "C_NoUnstanceCondition size mismatch");

} // namespace wh::xgenaimodule::NPCState
