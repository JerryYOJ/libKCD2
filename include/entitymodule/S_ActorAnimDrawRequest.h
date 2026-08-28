#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_ActionFullBodyAnimRequest.h"

namespace wh::entitymodule {

struct S_ActorAnimDrawRequest : S_ActionFullBodyAnimRequest {
    ~S_ActorAnimDrawRequest() override;                         // [0] 0x1828B15A4
    RTTR_ENABLE(S_ActionFullBodyAnimRequest)                    // [4..6]

    std::uint32_t m_unknownE8;                                 // +0xE8, initialized to 3
    std::uint16_t m_unknownEC;                                 // +0xEC
    std::uint8_t m_paddingEE[2];                               // +0xEE
    std::vector<CryStringT<char>> m_unknownF0;                 // +0xF0
    bool m_unknown108;                                         // +0x108
    std::uint8_t m_padding109[7];                              // +0x109
    std::uint64_t m_unknown110[2];                             // +0x110
    std::uint32_t m_unknown120;                                // +0x120
    bool m_unknown124;                                         // +0x124
    std::uint8_t m_padding125[0x0B];                           // +0x125
};

static_assert(offsetof(S_ActorAnimDrawRequest, m_unknownE8) == 0xE8,
              "S_ActorAnimDrawRequest::m_unknownE8 offset mismatch");
static_assert(offsetof(S_ActorAnimDrawRequest, m_unknownF0) == 0xF0,
              "S_ActorAnimDrawRequest::m_unknownF0 offset mismatch");
static_assert(offsetof(S_ActorAnimDrawRequest, m_unknown110) == 0x110,
              "S_ActorAnimDrawRequest::m_unknown110 offset mismatch");
static_assert(sizeof(S_ActorAnimDrawRequest) == 0x130,
              "S_ActorAnimDrawRequest size mismatch");

}  // namespace wh::entitymodule
