#pragma once

#include <cstddef>

namespace wh::xgenaimodule::BehaviorTree {

class I_CallbackEventSource {
public:
    virtual void unk_0() = 0;                                                // [0]
};

static_assert(sizeof(I_CallbackEventSource) == 0x08,
              "I_CallbackEventSource size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
