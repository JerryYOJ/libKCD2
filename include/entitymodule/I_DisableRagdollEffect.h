#pragma once

#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class I_DisableRagdollEffect {
public:
    virtual void DisableRagdollEffect() = 0; // [0] behavior-derived; Dead 0x1816D5430, Unconscious 0x181A82B00
    RTTR_ENABLE()                            // [1..3]
};

static_assert(sizeof(I_DisableRagdollEffect) == 0x08,
              "I_DisableRagdollEffect size mismatch");

} // namespace wh::entitymodule
