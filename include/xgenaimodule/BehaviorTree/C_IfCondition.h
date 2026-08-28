#pragma once

#include <cstddef>
#include <cstdint>

#include "C_Decorator.h"
#include "C_NodeWrapper.h"
#include "I_ContinuousSwitchableNode.h"
#include "S_IfConditionContext.h"

namespace wh::xgenaimodule::BehaviorTree {

using C_IfConditionBase =
    C_NodeWrapper<class C_IfCondition, C_Decorator, S_IfConditionContext>;

class C_IfCondition : public I_ContinuousSwitchableNode,
                      public C_IfConditionBase {
public:
    ~C_IfCondition() override;
    RTTR_ENABLE(C_IfConditionBase)                                           // [5..7], vtable 0x183A355C8

    std::uint8_t m_unknown40[8];                                             // +0x40
};

static_assert(sizeof(C_IfCondition) == 0x48,
              "C_IfCondition size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
