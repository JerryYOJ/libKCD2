#pragma once

#include <cstddef>

#include "C_Decorator.h"
#include "C_NodeWrapper.h"
#include "I_ContinuousSwitchableNode.h"
#include "S_TimerBoxContext.h"

namespace wh::xgenaimodule::BehaviorTree {

using C_TimerBoxBase =
    C_NodeWrapper<class C_TimerBox, C_Decorator, S_TimerBoxContext>;

class C_TimerBox : public I_ContinuousSwitchableNode, public C_TimerBoxBase {
public:
    ~C_TimerBox() override;
    RTTR_ENABLE(C_TimerBoxBase)                                              // [5..7], vtable 0x183AE7A70
};

static_assert(sizeof(C_TimerBox) == 0x40,
              "C_TimerBox size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
