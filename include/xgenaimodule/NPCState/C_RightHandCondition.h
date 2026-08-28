#pragma once
#include <cstddef>
#include "C_HandContentConditionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_RightHandCondition : public C_HandContentConditionBase {
public:
    ~C_RightHandCondition() override;
    I_Condition* unk_01() override;
    std::uint16_t unk_05() override;
    std::uint32_t unk_09() override;
    void unk_10(void* out, void* arg) override;
    RTTR_ENABLE(C_HandContentConditionBase)
};

static_assert(sizeof(C_RightHandCondition) == 0x40,
              "C_RightHandCondition size mismatch");

}  // namespace wh::xgenaimodule::NPCState
