#pragma once

#include <cstddef>
#include <cstdint>

#include "S_ActionQueryData.h"

namespace wh::entitymodule {

class S_ActionIdleQueryData : public S_ActionQueryData {
public:
    RTTR_ENABLE(S_ActionQueryData)                          // [0..2]

    std::uint32_t m_idleStateId;                            // +0x28, initialized -1
    std::uint8_t m_padding2C[4];                            // +0x2C
};

static_assert(offsetof(S_ActionIdleQueryData, m_idleStateId) == 0x28,
              "S_ActionIdleQueryData::m_idleStateId offset mismatch");
static_assert(sizeof(S_ActionIdleQueryData) == 0x30,
              "S_ActionIdleQueryData size mismatch");

}  // namespace wh::entitymodule
