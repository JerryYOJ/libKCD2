#pragma once

#include <cstddef>

#include "C_ItemSetAsideElement.h"

namespace wh::xgenaimodule::NPCState {

class C_ExplicitItemPlacedElement : public C_ItemSetAsideElement {
public:
    ~C_ExplicitItemPlacedElement() override;                                 // [0] 0x1811E95A0
    RTTR_ENABLE(C_ItemSetAsideElement)                                       // [30..32], vtable 0x183B01958
};

static_assert(sizeof(C_ExplicitItemPlacedElement) == 0x40,
              "C_ExplicitItemPlacedElement size mismatch");

} // namespace wh::xgenaimodule::NPCState
