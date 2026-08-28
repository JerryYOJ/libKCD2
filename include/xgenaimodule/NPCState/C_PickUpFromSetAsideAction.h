#pragma once

#include <cstddef>

#include "C_PickUpAction.h"

namespace wh::xgenaimodule::NPCState {

class C_PickUpFromSetAsideAction : public C_PickUpAction {
public:
    ~C_PickUpFromSetAsideAction() override;
    RTTR_ENABLE(C_PickUpAction)                                              // [24..26], vtable 0x183B5C2B8
};

static_assert(sizeof(C_PickUpFromSetAsideAction) == 0x1C8,
              "C_PickUpFromSetAsideAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
