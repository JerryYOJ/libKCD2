#pragma once

#include <cstddef>
#include <cstdint>

#include "S_ActionIdleQueryData.h"

namespace wh::entitymodule {

class S_DogActionQueryData : public S_ActionIdleQueryData {
public:
    RTTR_ENABLE(S_ActionIdleQueryData)                      // [0..2], vtable 0x183A2C070

    bool m_flag30;                                         // +0x30
    std::uint8_t m_padding31[3];                           // +0x31
    std::uint32_t m_stateValue34;                          // +0x34
    bool m_flag38;                                         // +0x38
    std::uint8_t m_padding39[7];                           // +0x39
};

static_assert(offsetof(S_DogActionQueryData, m_stateValue34) == 0x34,
              "S_DogActionQueryData::m_stateValue34 offset mismatch");
static_assert(sizeof(S_DogActionQueryData) == 0x40,
              "S_DogActionQueryData size mismatch");

}  // namespace wh::entitymodule
