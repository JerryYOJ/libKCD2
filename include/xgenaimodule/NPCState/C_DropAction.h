#pragma once

#include <cstddef>

#include "C_PlaceAction.h"

namespace wh::xgenaimodule::NPCState {

class C_DropAction : public C_PlaceAction {
public:
    ~C_DropAction() override;
    RTTR_ENABLE(C_PlaceAction)                                               // [24..26], vtable 0x183B5B168
};

static_assert(sizeof(C_DropAction) == 0x1C0,
              "C_DropAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
