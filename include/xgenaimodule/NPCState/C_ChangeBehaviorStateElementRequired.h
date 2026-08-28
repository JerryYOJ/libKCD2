#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ChangeBehaviorStateElement.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeBehaviorStateElementRequired : public C_ChangeBehaviorStateElement {
public:
    C_ChangeBehaviorStateElementRequired();                              // 0x181873E70
    ~C_ChangeBehaviorStateElementRequired() override;                    // [0]
    RTTR_ENABLE(C_ChangeBehaviorStateElement)                            // [30..32], vtable 0x183B5DDF8

    std::uint8_t m_unknown30[8];                                         // +0x30
};

static_assert(sizeof(C_ChangeBehaviorStateElementRequired) == 0x38,
              "C_ChangeBehaviorStateElementRequired size mismatch");

} // namespace wh::xgenaimodule::NPCState
