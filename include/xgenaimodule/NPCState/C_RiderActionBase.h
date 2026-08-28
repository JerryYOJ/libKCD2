#pragma once

#include <cstddef>
#include <cstdint>

#include "C_CodeAction.h"

namespace wh::xgenaimodule::NPCState {

class C_RiderActionBase : public C_CodeAction {
public:
    ~C_RiderActionBase() override;                                           // [0] 0x183386E40
    RTTR_ENABLE(C_CodeAction)                                                // [24..26], vtable 0x183B3F440

    std::uint8_t m_unknownC0[0x20];                                          // +0xC0
};

static_assert(sizeof(C_RiderActionBase) == 0xE0,
              "C_RiderActionBase size mismatch");

} // namespace wh::xgenaimodule::NPCState
