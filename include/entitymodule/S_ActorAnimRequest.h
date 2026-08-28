#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>

#include "../animationmodule/S_AnimatedActionTagState.h"
#include "S_ActionFullBodyAnimRequest.h"
#include "S_ActorAnimRequestData.h"

namespace wh::entitymodule {

struct S_ActorAnimRequest : S_ActionFullBodyAnimRequest {
    ~S_ActorAnimRequest() override;                         // [0] 0x1828B1660
    RTTR_ENABLE(S_ActionFullBodyAnimRequest)                 // [4..6], vtable 0x183A5DB98

    std::uint64_t m_unknownE8;                              // +0xE8, unloaded runtime-global default
    std::uint16_t m_unknownF0;                              // +0xF0, initialized 1
    std::uint16_t m_paddingF2;                              // +0xF2
    std::int32_t m_valueF4;                                 // +0xF4, initialized 0
    bool m_flagF8;                                          // +0xF8
    bool m_flagF9;                                          // +0xF9
    std::uint8_t m_paddingFA[2];                            // +0xFA
    std::uint32_t m_valueFC;                                // +0xFC, initialized 0
    bool m_flag100;                                         // +0x100
    std::uint8_t m_padding101[3];                           // +0x101
    std::optional<std::int32_t> m_value104;                 // +0x104
    std::optional<std::int32_t> m_value10C;                 // +0x10C
    bool m_flag114;                                         // +0x114
    bool m_flag115;                                         // +0x115
    std::uint8_t m_padding116[2];                           // +0x116
    std::int32_t m_fragmentId;                              // +0x118, initialized -1
    wh::animationmodule::S_AnimatedActionTagState m_globalTags;   // +0x11C
    wh::animationmodule::S_AnimatedActionTagState m_fragmentTags; // +0x130
    std::uint32_t m_padding144;                             // +0x144
    CryStringT<char> m_fragmentName;                        // +0x148
    CryStringT<char> m_tagStateName;                        // +0x150, initialized "AnyTagState"
    bool m_useCurrentTagState;                              // +0x158, initialized true
    std::uint8_t m_unknown159;                              // +0x159
    bool m_flag15A;                                         // +0x15A
    std::uint8_t m_padding15B;                              // +0x15B
    std::uint32_t m_unknown15C;                             // +0x15C
    S_ActorAnimRequestData m_data160;                       // +0x160
    std::shared_ptr<void> m_unknown180;                     // +0x180, pointee type unresolved
    std::shared_ptr<void> m_unknown190;                     // +0x190, pointee type unresolved
    std::optional<std::int32_t> m_value1A0;                 // +0x1A0
    std::optional<std::uint64_t> m_value1A8;                // +0x1A8
    std::uint8_t m_unknown1B8[0x38];                        // +0x1B8
    bool m_flag1F0;                                         // +0x1F0
    std::uint8_t m_padding1F1[7];                           // +0x1F1
};

static_assert(offsetof(S_ActorAnimRequest, m_value104) == 0x104,
              "S_ActorAnimRequest::m_value104 offset mismatch");
static_assert(offsetof(S_ActorAnimRequest, m_fragmentId) == 0x118,
              "S_ActorAnimRequest::m_fragmentId offset mismatch");
static_assert(offsetof(S_ActorAnimRequest, m_globalTags) == 0x11C,
              "S_ActorAnimRequest::m_globalTags offset mismatch");
static_assert(offsetof(S_ActorAnimRequest, m_data160) == 0x160,
              "S_ActorAnimRequest::m_data160 offset mismatch");
static_assert(offsetof(S_ActorAnimRequest, m_unknown180) == 0x180,
              "S_ActorAnimRequest::m_unknown180 offset mismatch");
static_assert(offsetof(S_ActorAnimRequest, m_value1A8) == 0x1A8,
              "S_ActorAnimRequest::m_value1A8 offset mismatch");
static_assert(sizeof(S_ActorAnimRequest) == 0x1F8,
              "S_ActorAnimRequest size mismatch");

}  // namespace wh::entitymodule
