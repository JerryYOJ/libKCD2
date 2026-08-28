#pragma once

#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class I_ActorActionCarry {
public:
    virtual void unk_0() = 0;                                            // [0] CarryCorpse 0x18287CA38, CarryItem 0x181A82520
    RTTR_ENABLE()                                                        // [1..3]
};

static_assert(sizeof(I_ActorActionCarry) == 0x08,
              "I_ActorActionCarry size mismatch");

} // namespace wh::entitymodule
