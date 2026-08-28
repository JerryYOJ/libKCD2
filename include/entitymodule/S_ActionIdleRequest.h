#pragma once

#include <cstddef>
#include <cstdint>

#include "S_ActionFullBodyAnimRequest.h"

namespace wh::entitymodule {

struct S_ActionIdleRequest : S_ActionFullBodyAnimRequest {
    ~S_ActionIdleRequest() override;
    RTTR_ENABLE(S_ActionFullBodyAnimRequest)                    // [4..6]

    std::int32_t m_unknownE8;                                  // +0xE8, initialized 0
    std::uint32_t m_paddingEC;                                 // +0xEC
};

static_assert(offsetof(S_ActionIdleRequest, m_unknownE8) == 0xE8,
              "S_ActionIdleRequest::m_unknownE8 offset mismatch");
static_assert(sizeof(S_ActionIdleRequest) == 0xF0,
              "S_ActionIdleRequest size mismatch");

}  // namespace wh::entitymodule
