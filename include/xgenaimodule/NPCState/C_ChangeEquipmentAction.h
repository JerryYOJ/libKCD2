#pragma once

#include <cstddef>
#include <cstdint>

#include "C_StashManipulationAction.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeEquipmentAction : public C_StashManipulationAction {
public:
    ~C_ChangeEquipmentAction() override;
    RTTR_ENABLE(C_StashManipulationAction)                                   // [24..26], vtable 0x183A47A98

    std::uint8_t m_unknown1B0[0x50];                                         // +0x1B0
};

static_assert(sizeof(C_ChangeEquipmentAction) == 0x200,
              "C_ChangeEquipmentAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
