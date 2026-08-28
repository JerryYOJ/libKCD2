#pragma once

#include <cstddef>
#include <cstdint>

#include "C_StanceElement.h"

namespace wh::xgenaimodule::NPCState {

class C_StanceElementRequired : public C_StanceElement {
public:
    C_StanceElementRequired();                                           // 0x18186E7B4
    ~C_StanceElementRequired() override;                                 // [0]
    RTTR_ENABLE(C_StanceElement)                                         // [30..32], vtable 0x183A54E08

    std::uint8_t m_unknown50[8];                                         // +0x50
};

static_assert(sizeof(C_StanceElementRequired) == 0x58,
              "C_StanceElementRequired size mismatch");

} // namespace wh::xgenaimodule::NPCState
