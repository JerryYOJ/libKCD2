#pragma once

#include <cstddef>

namespace wh::xgenaimodule {

class I_IntermissionAwaiter {
public:
    virtual void OnIntermission() = 0;                                       // [0]
    virtual void unk_1() = 0;                                                // [1]
};

static_assert(sizeof(I_IntermissionAwaiter) == 0x08,
              "I_IntermissionAwaiter size mismatch");

} // namespace wh::xgenaimodule
