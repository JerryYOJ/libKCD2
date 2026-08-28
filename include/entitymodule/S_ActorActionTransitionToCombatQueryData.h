#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>

#include "S_ActionQueryData.h"

namespace wh::entitymodule {

class S_ActorActionTransitionToCombatQueryData : public S_ActionQueryData {
public:
    RTTR_ENABLE(S_ActionQueryData)                          // [0..2], vtable 0x18470AC70

    bool m_flag28;                                         // +0x28
    std::uint8_t m_padding29[3];                           // +0x29
    std::int32_t m_stateValue2C;                           // +0x2C
    bool m_flag30;                                         // +0x30
    std::uint8_t m_padding31[3];                           // +0x31
    std::optional<std::int32_t> m_value34;                 // +0x34
    std::optional<std::int32_t> m_value3C;                 // +0x3C
    std::uint8_t m_padding44[4];                           // +0x44
    bool m_flag48;                                         // +0x48
    std::uint8_t m_padding49[7];                           // +0x49
    bool m_flag50;                                         // +0x50
    std::uint8_t m_padding51[7];                           // +0x51
};

static_assert(sizeof(std::optional<std::int32_t>) == 0x08,
              "MSVC optional<int32_t> size mismatch");
static_assert(offsetof(S_ActorActionTransitionToCombatQueryData, m_value34) == 0x34,
              "S_ActorActionTransitionToCombatQueryData::m_value34 offset mismatch");
static_assert(offsetof(S_ActorActionTransitionToCombatQueryData, m_flag50) == 0x50,
              "S_ActorActionTransitionToCombatQueryData::m_flag50 offset mismatch");
static_assert(sizeof(S_ActorActionTransitionToCombatQueryData) == 0x58,
              "S_ActorActionTransitionToCombatQueryData size mismatch");

}  // namespace wh::entitymodule
