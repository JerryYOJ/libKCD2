#pragma once
#include <cstddef>
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionIsWeapon : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionIsWeapon() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
};

static_assert(sizeof(C_FilteringConditionIsWeapon) == 0x18,
              "C_FilteringConditionIsWeapon size mismatch");

}  // namespace wh::xgenaimodule::NPCState
