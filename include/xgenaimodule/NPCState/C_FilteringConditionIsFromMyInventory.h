#pragma once
#include <cstddef>
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionIsFromMyInventory : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionIsFromMyInventory() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
};

static_assert(sizeof(C_FilteringConditionIsFromMyInventory) == 0x18,
              "C_FilteringConditionIsFromMyInventory size mismatch");

}  // namespace wh::xgenaimodule::NPCState
