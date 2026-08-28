#pragma once
#include <cstddef>
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionIsEquipped : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionIsEquipped() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
};

static_assert(sizeof(C_FilteringConditionIsEquipped) == 0x18,
              "C_FilteringConditionIsEquipped size mismatch");

}  // namespace wh::xgenaimodule::NPCState
