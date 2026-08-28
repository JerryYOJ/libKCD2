#pragma once
#include <cstddef>
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionIsQuestItem : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionIsQuestItem() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
};

static_assert(sizeof(C_FilteringConditionIsQuestItem) == 0x18,
              "C_FilteringConditionIsQuestItem size mismatch");

}  // namespace wh::xgenaimodule::NPCState
