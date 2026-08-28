#pragma once

#include <cstddef>

#include "../../rttr/rttr_enable.h"

namespace wh::xgenaimodule::BehaviorTree {

class I_CallbackEventConsumer {
public:
    RTTR_ENABLE()                                                            // [0..2]
    virtual ~I_CallbackEventConsumer();                                      // [3]
};

static_assert(sizeof(I_CallbackEventConsumer) == 0x08,
              "I_CallbackEventConsumer size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
