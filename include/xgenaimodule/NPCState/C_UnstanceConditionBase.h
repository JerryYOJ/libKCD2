#pragma once

#include "I_Condition.h"

namespace wh::xgenaimodule::NPCState {

class C_UnstanceConditionBase : public I_Condition {
public:
    virtual void unk_09();                                               // [9]
};

static_assert(sizeof(C_UnstanceConditionBase) == 0x08,
              "C_UnstanceConditionBase size mismatch");

} // namespace wh::xgenaimodule::NPCState
