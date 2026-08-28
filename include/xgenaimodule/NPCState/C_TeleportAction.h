#pragma once

#include <cstddef>
#include <cstdint>

#include "C_CodeAction.h"

namespace wh::xgenaimodule::NPCState {

class C_TeleportAction : public C_CodeAction {
public:
    ~C_TeleportAction() override;
    RTTR_ENABLE(C_CodeAction)                                                // [24..26], vtable 0x183C0A7C0

    std::uint8_t m_unknownC0[0x30];                                          // +0xC0
};

static_assert(sizeof(C_TeleportAction) == 0xF0,
              "C_TeleportAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
