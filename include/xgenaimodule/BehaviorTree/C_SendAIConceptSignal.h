#pragma once

#include <cstddef>

#include "C_Node.h"
#include "C_NodeWrapper.h"
#include "S_BaseNodeContext.h"
#include "S_BaseNodeContextGeneratedAttributes.h"

namespace wh::xgenaimodule::BehaviorTree {

using C_SendAIConceptSignalBase = C_NodeWrapperGeneratedAttributes<
    class C_SendAIConceptSignal, C_Node,
    S_BaseNodeContextGeneratedAttributes<S_BaseNodeContext>>;

class C_SendAIConceptSignal : public C_SendAIConceptSignalBase {
public:
    ~C_SendAIConceptSignal() override;
    RTTR_ENABLE(C_SendAIConceptSignalBase)                                   // [5..7], vtable 0x183ACA2F8
};

static_assert(sizeof(C_SendAIConceptSignal) == 0x30,
              "C_SendAIConceptSignal size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
