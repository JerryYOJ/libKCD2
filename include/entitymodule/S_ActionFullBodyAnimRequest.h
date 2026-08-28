#pragma once
#include "S_ActionAnimRequest.h"

namespace wh::entitymodule {

struct S_ActionFullBodyAnimRequest : S_ActionAnimRequest {
    ~S_ActionFullBodyAnimRequest() override;
    RTTR_ENABLE(S_ActionAnimRequest)                            // [4..6]
};

static_assert(sizeof(S_ActionFullBodyAnimRequest) == 0xE8,
              "S_ActionFullBodyAnimRequest size mismatch");

}  // namespace wh::entitymodule
