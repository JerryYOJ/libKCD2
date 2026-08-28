#pragma once
#include <cstddef>
#include "../../rttr/rttr_enable.h"

namespace wh::xgenaimodule::BehaviorTree {

class I_BehaviorTag {
public:
    RTTR_ENABLE()                                           // [0..2]
    virtual ~I_BehaviorTag();                               // [3]
};

static_assert(sizeof(I_BehaviorTag) == 0x08,
              "I_BehaviorTag size mismatch");

}  // namespace wh::xgenaimodule::BehaviorTree
