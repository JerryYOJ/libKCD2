#pragma once

#include <cstddef>

#include "C_Node.h"

namespace wh::xgenaimodule::BehaviorTree {

class C_Decorator : public C_Node {
public:
    ~C_Decorator() override;
    RTTR_ENABLE(C_Node)                                                      // [5..7], vtable 0x183A36428
};

static_assert(sizeof(C_Decorator) == 0x30,
              "BehaviorTree::C_Decorator size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
