#pragma once
#include "S_ActionAnimRequest.h"

namespace wh::entitymodule {

struct S_ActionAdditiveAnimRequest : S_ActionAnimRequest {
    ~S_ActionAdditiveAnimRequest() override;
    RTTR_ENABLE(S_ActionAnimRequest)                            // [4..6]
};

static_assert(sizeof(S_ActionAdditiveAnimRequest) == 0xE8,
              "S_ActionAdditiveAnimRequest size mismatch");

}  // namespace wh::entitymodule
