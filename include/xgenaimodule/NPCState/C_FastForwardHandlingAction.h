#pragma once

#include <cstddef>
#include <cstdint>

#include "C_CodeAction.h"

namespace wh::xgenaimodule::NPCState {

class C_FastForwardHandlingAction : public C_CodeAction {
public:
    ~C_FastForwardHandlingAction() override;
    RTTR_ENABLE(C_CodeAction)                                            // [24..26], vtable 0x183A2E2D8

    std::uint8_t m_unknownC0[8];                                         // +0xC0
};

static_assert(sizeof(C_FastForwardHandlingAction) == 0xC8,
              "C_FastForwardHandlingAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
