#pragma once

#include <cstddef>

#include "C_FixedComposite.h"
#include "C_NodeWrapper.h"
#include "I_SwitchableNode.h"
#include "S_GateContext.h"

namespace wh::xgenaimodule::BehaviorTree {

using C_GateBase =
    C_NodeWrapper<class C_Gate, C_FixedComposite<2>, S_GateContext>;

class C_Gate : public C_GateBase, public I_SwitchableNode {
public:
    ~C_Gate() override;
    RTTR_ENABLE(C_GateBase)                                                  // [5..7], vtable 0x183A34B38
};

static_assert(sizeof(C_Gate) == 0x78,
              "C_Gate size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
