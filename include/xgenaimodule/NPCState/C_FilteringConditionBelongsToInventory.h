#pragma once
#include <cstddef>
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionBelongsToInventory : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionBelongsToInventory() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
};

static_assert(sizeof(C_FilteringConditionBelongsToInventory) == 0x18,
              "C_FilteringConditionBelongsToInventory size mismatch");

}  // namespace wh::xgenaimodule::NPCState
