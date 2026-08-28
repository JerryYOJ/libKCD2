#pragma once

#include <cstddef>

#include "C_UnstanceActionIn.h"

namespace wh::xgenaimodule::NPCState {

class C_UnstanceActionInStatic : public C_UnstanceActionIn {
public:
    ~C_UnstanceActionInStatic() override;
    RTTR_ENABLE(C_UnstanceActionIn)                                          // [24..26], vtable 0x183B7DBC0
};

static_assert(sizeof(C_UnstanceActionInStatic) == 0x218,
              "C_UnstanceActionInStatic size mismatch");

} // namespace wh::xgenaimodule::NPCState
