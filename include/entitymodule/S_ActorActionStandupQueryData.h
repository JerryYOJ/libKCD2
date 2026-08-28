#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>

#include "S_ActionQueryData.h"

namespace wh::entitymodule {

class S_ActorActionStandupQueryData : public S_ActionQueryData {
public:
    RTTR_ENABLE(S_ActionQueryData)                          // [0..2], vtable 0x184709E38

    bool m_flag28;                                         // +0x28
    std::uint8_t m_padding29[3];                           // +0x29
    std::uint32_t m_stateValue2C;                          // +0x2C
    bool m_flag30;                                         // +0x30
    std::uint8_t m_padding31[3];                           // +0x31
    std::uint32_t m_stateValue34;                          // +0x34
    std::optional<std::int32_t> m_value38;                 // +0x38
    std::optional<std::int32_t> m_value40;                 // +0x40
    std::optional<std::int32_t> m_value48;                 // +0x48
};

static_assert(sizeof(std::optional<std::int32_t>) == 0x08,
              "MSVC optional<int32_t> size mismatch");
static_assert(offsetof(S_ActorActionStandupQueryData, m_value38) == 0x38,
              "S_ActorActionStandupQueryData::m_value38 offset mismatch");
static_assert(offsetof(S_ActorActionStandupQueryData, m_value48) == 0x48,
              "S_ActorActionStandupQueryData::m_value48 offset mismatch");
static_assert(sizeof(S_ActorActionStandupQueryData) == 0x50,
              "S_ActorActionStandupQueryData size mismatch");

}  // namespace wh::entitymodule
