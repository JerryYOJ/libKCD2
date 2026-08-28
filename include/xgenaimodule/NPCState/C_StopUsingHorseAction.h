#pragma once

#include <cstddef>
#include <cstdint>

#include "C_CodeAction.h"

namespace wh::xgenaimodule::NPCState {

class C_StopUsingHorseAction : public C_CodeAction {
public:
    ~C_StopUsingHorseAction() override;
    RTTR_ENABLE(C_CodeAction)                                                // [24..26], vtable 0x183B3FB30

    std::uint8_t m_unknownC0[0x18];                                          // +0xC0
};

static_assert(sizeof(C_StopUsingHorseAction) == 0xD8,
              "C_StopUsingHorseAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
