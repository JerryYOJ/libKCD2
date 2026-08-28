#pragma once

#include <cstddef>
#include <cstdint>

#include "C_FastForwardHandlingAction.h"

namespace wh::xgenaimodule::NPCState {

class C_DummyDebugAction : public C_FastForwardHandlingAction {
public:
    ~C_DummyDebugAction() override;
    RTTR_ENABLE(C_FastForwardHandlingAction)                                 // [24..26], vtable 0x18476C268

    std::uint8_t m_unknownC8[8];                                             // +0xC8
};

static_assert(sizeof(C_DummyDebugAction) == 0xD0,
              "C_DummyDebugAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
