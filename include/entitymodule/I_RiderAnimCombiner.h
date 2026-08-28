#pragma once

#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class I_RiderAnimCombiner {
public:
    virtual bool unk_0(bool flag, void* context) = 0;                    // [0] Combat 0x18287BAE8
    RTTR_ENABLE()                                                        // [1..3]
};

static_assert(sizeof(I_RiderAnimCombiner) == 0x08,
              "I_RiderAnimCombiner size mismatch");

} // namespace wh::entitymodule
