#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "S_ActionFullBodyAnimRequest.h"

namespace wh::entitymodule {

struct S_ActorAnimPickUpRequest : S_ActionFullBodyAnimRequest {
    ~S_ActorAnimPickUpRequest() override;                       // [0] 0x1815F08B0
    RTTR_ENABLE(S_ActionFullBodyAnimRequest)                    // [4..6]

    std::uint64_t m_unknownE8;                                 // +0xE8
    std::uint32_t m_unknownF0;                                 // +0xF0, initialized to 2
    std::uint16_t m_unknownF4;                                 // +0xF4
    std::uint16_t m_paddingF6;                                 // +0xF6
    std::shared_ptr<void> m_unknownF8;                         // +0xF8, pointee type OPEN
};

static_assert(offsetof(S_ActorAnimPickUpRequest, m_unknownE8) == 0xE8,
              "S_ActorAnimPickUpRequest::m_unknownE8 offset mismatch");
static_assert(offsetof(S_ActorAnimPickUpRequest, m_unknownF8) == 0xF8,
              "S_ActorAnimPickUpRequest::m_unknownF8 offset mismatch");
static_assert(sizeof(S_ActorAnimPickUpRequest) == 0x108,
              "S_ActorAnimPickUpRequest size mismatch");

}  // namespace wh::entitymodule
