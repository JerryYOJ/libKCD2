#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>

#include "S_ActionQueryData.h"

namespace wh::entitymodule {

class S_HitReactionQueryData : public S_ActionQueryData {
public:
    RTTR_ENABLE(S_ActionQueryData)                          // [0..2], vtable 0x183A797B8

    bool m_flag28;                                         // +0x28
    std::uint8_t m_padding29[3];                           // +0x29
    std::int32_t m_stateValue2C;                           // +0x2C
    bool m_flag30;                                         // +0x30
    bool m_flag31;                                         // +0x31
    std::uint8_t m_unknown32;                              // +0x32
    std::uint8_t m_padding33;                              // +0x33
    std::uint32_t m_stateValue34;                          // +0x34
    bool m_flag38;                                         // +0x38
    std::uint8_t m_padding39[3];                           // +0x39
    std::int32_t m_value3C;                                // +0x3C
    std::int32_t m_value40;                                // +0x40
    std::int32_t m_value44;                                // +0x44
    bool m_flag48;                                         // +0x48
    std::uint8_t m_padding49[3];                           // +0x49
    std::int32_t m_value4C;                                // +0x4C
    std::int32_t m_value50;                                // +0x50
    std::uint32_t m_values54[2];                           // +0x54
    std::uint32_t m_value5C;                               // +0x5C
    std::uint64_t m_unknown60;                             // +0x60
    std::optional<std::int32_t> m_value68;                 // +0x68
    std::optional<std::int32_t> m_value70;                 // +0x70
};

static_assert(sizeof(std::optional<std::int32_t>) == 0x08,
              "MSVC optional<int32_t> size mismatch");
static_assert(offsetof(S_HitReactionQueryData, m_values54) == 0x54,
              "S_HitReactionQueryData::m_values54 offset mismatch");
static_assert(offsetof(S_HitReactionQueryData, m_value68) == 0x68,
              "S_HitReactionQueryData::m_value68 offset mismatch");
static_assert(sizeof(S_HitReactionQueryData) == 0x78,
              "S_HitReactionQueryData size mismatch");

}  // namespace wh::entitymodule
