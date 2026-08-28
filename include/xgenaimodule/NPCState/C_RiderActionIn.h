#pragma once

#include <cstddef>
#include <cstdint>

#include "C_RiderActionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_RiderActionIn : public C_RiderActionBase {
public:
    ~C_RiderActionIn() override;
    RTTR_ENABLE(C_RiderActionBase)                                           // [24..26], vtable 0x183B3F588

    std::uint8_t m_unknownE0[8];                                             // +0xE0
};

static_assert(sizeof(C_RiderActionIn) == 0xE8,
              "C_RiderActionIn size mismatch");

} // namespace wh::xgenaimodule::NPCState
