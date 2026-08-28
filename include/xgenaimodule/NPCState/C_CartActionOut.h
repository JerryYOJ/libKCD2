#pragma once

#include <cstddef>
#include <cstdint>

#include "C_CartActionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_CartActionOut : public C_CartActionBase {
public:
    ~C_CartActionOut() override;
    RTTR_ENABLE(C_CartActionBase)                                            // [24..26], vtable 0x183B3F170

    std::uint8_t m_unknown108[8];                                            // +0x108
};

static_assert(sizeof(C_CartActionOut) == 0x110,
              "C_CartActionOut size mismatch");

} // namespace wh::xgenaimodule::NPCState
