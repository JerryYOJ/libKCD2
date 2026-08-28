#pragma once
#include <cstddef>
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionIsFromSlot : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionIsFromSlot() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
};

static_assert(sizeof(C_FilteringConditionIsFromSlot) == 0x18,
              "C_FilteringConditionIsFromSlot size mismatch");

}  // namespace wh::xgenaimodule::NPCState
