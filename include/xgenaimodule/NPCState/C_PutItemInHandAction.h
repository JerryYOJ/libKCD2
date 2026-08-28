#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ItemHandlingAction.h"

namespace wh::xgenaimodule::NPCState {

class C_PutItemInHandAction : public C_ItemHandlingAction {
public:
    ~C_PutItemInHandAction() override;
    RTTR_ENABLE(C_ItemHandlingAction)                                        // [24..26], vtable 0x183B5B3F0

    std::uint8_t m_unknown1B8[8];                                            // +0x1B8
};

static_assert(sizeof(C_PutItemInHandAction) == 0x1C0,
              "C_PutItemInHandAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
