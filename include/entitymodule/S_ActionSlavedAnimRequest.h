#pragma once
#include <cstddef>
#include <cstdint>
#include "S_ActionAnimRequest.h"

namespace wh::entitymodule {

struct S_ActionSlavedAnimRequest : S_ActionAnimRequest {
    ~S_ActionSlavedAnimRequest() override;
    RTTR_ENABLE(S_ActionAnimRequest)                            // [4..6]

    std::uint64_t m_unknownE8;                                 // +0xE8, initialized to zero
};

static_assert(offsetof(S_ActionSlavedAnimRequest, m_unknownE8) == 0xE8,
              "S_ActionSlavedAnimRequest::m_unknownE8 offset mismatch");
static_assert(sizeof(S_ActionSlavedAnimRequest) == 0xF0,
              "S_ActionSlavedAnimRequest size mismatch");

}  // namespace wh::entitymodule
