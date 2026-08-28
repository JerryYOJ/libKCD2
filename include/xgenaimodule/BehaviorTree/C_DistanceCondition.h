#pragma once

#include <cstddef>

#include "C_Decorator.h"
#include "C_NodeWrapper.h"
#include "I_ContinuousSwitchableNode.h"
#include "S_DistanceConditionContext.h"

namespace wh::xgenaimodule::BehaviorTree {

using C_DistanceConditionBase =
    C_NodeWrapper<class C_DistanceCondition, C_Decorator,
                  S_DistanceConditionContext>;

class C_DistanceCondition : public I_ContinuousSwitchableNode,
                            public C_DistanceConditionBase {
public:
    ~C_DistanceCondition() override;
    RTTR_ENABLE(C_DistanceConditionBase)                                     // [5..7], vtable 0x183AD3CE8
};

static_assert(sizeof(C_DistanceCondition) == 0x40,
              "C_DistanceCondition size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
