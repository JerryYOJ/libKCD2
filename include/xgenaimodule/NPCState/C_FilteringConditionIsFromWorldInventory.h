#pragma once
#include <cstddef>
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionIsFromWorldInventory : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionIsFromWorldInventory() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
};

static_assert(sizeof(C_FilteringConditionIsFromWorldInventory) == 0x18,
              "C_FilteringConditionIsFromWorldInventory size mismatch");

}  // namespace wh::xgenaimodule::NPCState
