#pragma once

#include <cstddef>
#include <cstdint>

#include "C_CartActionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_CartActionIn : public C_CartActionBase {
public:
    ~C_CartActionIn() override;
    RTTR_ENABLE(C_CartActionBase)                                            // [24..26], vtable 0x183B3F2C0

    std::uint8_t m_unknown108[8];                                            // +0x108
};

static_assert(sizeof(C_CartActionIn) == 0x110,
              "C_CartActionIn size mismatch");

} // namespace wh::xgenaimodule::NPCState
