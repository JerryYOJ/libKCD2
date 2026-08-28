#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>

#include "../animationmodule/S_AnimatedActionTagState.h"
#include "S_ActionQueryData.h"

namespace wh::entitymodule {

class S_ActorAnimActionQueryData : public S_ActionQueryData {
public:
    RTTR_ENABLE(S_ActionQueryData)                          // [0..2], vtable 0x183E7E018

    bool m_flag28;                                         // +0x28
    std::uint8_t m_padding29[3];                           // +0x29
    std::int32_t m_stateValue2C;                           // +0x2C
    bool m_flag30;                                         // +0x30
    std::uint8_t m_padding31[3];                           // +0x31
    std::optional<std::int32_t> m_value34;                 // +0x34
    std::optional<std::int32_t> m_value3C;                 // +0x3C
    std::optional<std::int32_t> m_value44;                 // +0x44
    std::optional<std::int32_t> m_value4C;                 // +0x4C
    std::int32_t m_value54;                                // +0x54
    bool m_flag58;                                         // +0x58
    bool m_flag59;                                         // +0x59
    std::uint8_t m_padding5A[2];                           // +0x5A
    std::uint32_t m_values5C[2];                           // +0x5C
    std::optional<bool> m_flag64;                          // +0x64
    std::uint8_t m_padding66[2];                           // +0x66
    std::int32_t m_value68;                                // +0x68
    wh::animationmodule::S_AnimatedActionTagState m_globalTags;   // +0x6C
    wh::animationmodule::S_AnimatedActionTagState m_fragmentTags; // +0x80
    std::uint16_t m_unknown94;                             // +0x94
    std::uint8_t m_unknown96;                              // +0x96
    bool m_hasTransformData;                               // +0x97
    std::optional<std::uint64_t> m_value98;                // +0x98
    bool m_flagA8;                                         // +0xA8
    std::uint8_t m_paddingA9[7];                           // +0xA9
};

static_assert(sizeof(std::optional<std::int32_t>) == 0x08,
              "MSVC optional<int32_t> size mismatch");
static_assert(sizeof(std::optional<bool>) == 0x02,
              "MSVC optional<bool> size mismatch");
static_assert(sizeof(std::optional<std::uint64_t>) == 0x10,
              "MSVC optional<uint64_t> size mismatch");
static_assert(offsetof(S_ActorAnimActionQueryData, m_globalTags) == 0x6C,
              "S_ActorAnimActionQueryData::m_globalTags offset mismatch");
static_assert(offsetof(S_ActorAnimActionQueryData, m_fragmentTags) == 0x80,
              "S_ActorAnimActionQueryData::m_fragmentTags offset mismatch");
static_assert(offsetof(S_ActorAnimActionQueryData, m_value98) == 0x98,
              "S_ActorAnimActionQueryData::m_value98 offset mismatch");
static_assert(sizeof(S_ActorAnimActionQueryData) == 0xB0,
              "S_ActorAnimActionQueryData size mismatch");

}  // namespace wh::entitymodule
