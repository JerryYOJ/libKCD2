#pragma once
#include <cstddef>
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionIsInWorldInventory : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionIsInWorldInventory() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
};

static_assert(sizeof(C_FilteringConditionIsInWorldInventory) == 0x18,
              "C_FilteringConditionIsInWorldInventory size mismatch");

}  // namespace wh::xgenaimodule::NPCState
