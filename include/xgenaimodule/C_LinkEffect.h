#pragma once

#include <cstddef>

#include "C_LinkEffectBase.h"

namespace wh::xgenaimodule {

class C_LinkEffect : public C_LinkEffectBase {
public:
    C_LinkEffect();                                                      // 0x1802BD400
    ~C_LinkEffect() override;                                            // [0] 0x18199AFD0
    RTTR_ENABLE(C_LinkEffectBase)                                        // [5..7], vtable 0x183AEB968
};

static_assert(sizeof(C_LinkEffect) == 0x150,
              "C_LinkEffect size mismatch");

} // namespace wh::xgenaimodule
