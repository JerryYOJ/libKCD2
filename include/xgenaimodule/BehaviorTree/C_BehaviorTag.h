#pragma once

#include <cstddef>

#include "C_Node.h"
#include "I_BehaviorTag.h"

namespace wh::xgenaimodule::BehaviorTree {

class C_BehaviorTag : public C_Node, public I_BehaviorTag {
public:
    ~C_BehaviorTag() override;
    RTTR_ENABLE(C_Node)                                                      // [5..7]
};

static_assert(sizeof(C_BehaviorTag) == 0x38,
              "C_BehaviorTag size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
