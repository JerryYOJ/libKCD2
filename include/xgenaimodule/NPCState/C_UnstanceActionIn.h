#pragma once

#include <cstddef>

#include "C_ChangeUnstanceAction.h"

namespace wh::xgenaimodule::NPCState {

class C_UnstanceActionIn : public C_ChangeUnstanceAction {
public:
    ~C_UnstanceActionIn() override;
    RTTR_ENABLE(C_ChangeUnstanceAction)                                      // [24..26], vtable 0x183A2EB20
};

static_assert(sizeof(C_UnstanceActionIn) == 0x218,
              "C_UnstanceActionIn size mismatch");

} // namespace wh::xgenaimodule::NPCState
