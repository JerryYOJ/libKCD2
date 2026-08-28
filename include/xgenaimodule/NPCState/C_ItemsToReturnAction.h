#pragma once

#include <cstddef>
#include <cstdint>

#include "C_StashManipulationAction.h"

namespace wh::xgenaimodule::NPCState {

class C_ItemsToReturnAction : public C_StashManipulationAction {
public:
    ~C_ItemsToReturnAction() override;
    RTTR_ENABLE(C_StashManipulationAction)                                   // [24..26], vtable 0x183B5CA88

    std::uint8_t m_unknown1B0[8];                                            // +0x1B0
};

static_assert(sizeof(C_ItemsToReturnAction) == 0x1B8,
              "C_ItemsToReturnAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
