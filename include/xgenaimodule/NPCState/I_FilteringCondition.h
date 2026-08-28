#pragma once
#include <cstddef>
#include "../../rttr/rttr_enable.h"

namespace wh::xgenaimodule::NPCState {

class I_FilteringCondition {
public:
    virtual ~I_FilteringCondition();                      // [0] 0x18336C250
    virtual void unk_01() = 0;                            // [1]
    virtual bool unk_02() = 0;                            // [2] C_FilteringConditionBase calls [7]
    virtual bool unk_03() = 0;                            // [3] C_FilteringConditionBase calls [8]
    RTTR_ENABLE()                                         // [4..6]
};

static_assert(sizeof(I_FilteringCondition) == 0x08,
              "I_FilteringCondition size mismatch");

}  // namespace wh::xgenaimodule::NPCState
