#pragma once

#include <cstddef>

#include "C_PlaceAction.h"

namespace wh::xgenaimodule::NPCState {

class C_PlaceSetAsideAction : public C_PlaceAction {
public:
    ~C_PlaceSetAsideAction() override;
    RTTR_ENABLE(C_PlaceAction)                                               // [24..26], vtable 0x183B5C500
};

static_assert(sizeof(C_PlaceSetAsideAction) == 0x1C0,
              "C_PlaceSetAsideAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
