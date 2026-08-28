#pragma once
#include "S_ActionFullBodyAnimRequest.h"

namespace wh::entitymodule {

struct S_ActorAnimHolsterRequest : S_ActionFullBodyAnimRequest {
    ~S_ActorAnimHolsterRequest() override;
    RTTR_ENABLE(S_ActionFullBodyAnimRequest)                    // [4..6]
};

static_assert(sizeof(S_ActorAnimHolsterRequest) == 0xE8,
              "S_ActorAnimHolsterRequest size mismatch");

}  // namespace wh::entitymodule
