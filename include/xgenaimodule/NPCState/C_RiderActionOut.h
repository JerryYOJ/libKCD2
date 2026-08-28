#pragma once

#include <cstddef>
#include <cstdint>

#include "C_RiderActionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_RiderActionOut : public C_RiderActionBase {
public:
    ~C_RiderActionOut() override;
    RTTR_ENABLE(C_RiderActionBase)                                           // [24..26], vtable 0x183B3F6D0

    std::uint8_t m_unknownE0[0x48];                                          // +0xE0
};

static_assert(sizeof(C_RiderActionOut) == 0x128,
              "C_RiderActionOut size mismatch");

} // namespace wh::xgenaimodule::NPCState
