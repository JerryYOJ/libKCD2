#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ItemHandlingAction.h"

namespace wh::xgenaimodule::NPCState {

class C_PutItemInInventoryAction : public C_ItemHandlingAction {
public:
    ~C_PutItemInInventoryAction() override;
    RTTR_ENABLE(C_ItemHandlingAction)                                        // [24..26], vtable 0x183B5C750

    std::uint8_t m_unknown1B8[8];                                            // +0x1B8
};

static_assert(sizeof(C_PutItemInInventoryAction) == 0x1C0,
              "C_PutItemInInventoryAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
