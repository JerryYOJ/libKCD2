#pragma once

#include <cstddef>

#include "C_CodeAction.h"

namespace wh::xgenaimodule::NPCState {

class C_SuccessAction : public C_CodeAction {
public:
    C_SuccessAction();                                                   // 0x18186E4DC
    ~C_SuccessAction() override;                                         // [0]
    RTTR_ENABLE(C_CodeAction)                                            // [24..26], vtable 0x183B3F838
};

static_assert(sizeof(C_SuccessAction) == 0xC0,
              "C_SuccessAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
