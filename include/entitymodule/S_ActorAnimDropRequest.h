#pragma once
#include <cstddef>
#include <cstdint>
#include "S_ActionFullBodyAnimRequest.h"

namespace wh::entitymodule {

struct S_ActorAnimDropRequest : S_ActionFullBodyAnimRequest {
    ~S_ActorAnimDropRequest() override;
    RTTR_ENABLE(S_ActionFullBodyAnimRequest)                    // [4..6]

    std::uint32_t m_unknownE8;                                 // +0xE8, initialized to 2
    std::uint32_t m_paddingEC;                                 // +0xEC
};

static_assert(offsetof(S_ActorAnimDropRequest, m_unknownE8) == 0xE8,
              "S_ActorAnimDropRequest::m_unknownE8 offset mismatch");
static_assert(sizeof(S_ActorAnimDropRequest) == 0xF0,
              "S_ActorAnimDropRequest size mismatch");

}  // namespace wh::entitymodule
