#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ItemHandlingAction.h"

namespace wh::xgenaimodule::NPCState {

class C_PickUpAction : public C_ItemHandlingAction {
public:
    ~C_PickUpAction() override;
    RTTR_ENABLE(C_ItemHandlingAction)                                        // [24..26], vtable 0x183B5BE20

    std::uint8_t m_unknown1B8[0x10];                                         // +0x1B8
};

static_assert(sizeof(C_PickUpAction) == 0x1C8,
              "C_PickUpAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
