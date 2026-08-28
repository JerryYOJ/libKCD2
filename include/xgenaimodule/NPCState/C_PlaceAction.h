#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ItemHandlingAction.h"

namespace wh::xgenaimodule::NPCState {

class C_PlaceAction : public C_ItemHandlingAction {
public:
    ~C_PlaceAction() override;
    RTTR_ENABLE(C_ItemHandlingAction)                                        // [24..26], vtable 0x183B5C068

    std::uint8_t m_unknown1B8[8];                                            // +0x1B8
};

static_assert(sizeof(C_PlaceAction) == 0x1C0,
              "C_PlaceAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
