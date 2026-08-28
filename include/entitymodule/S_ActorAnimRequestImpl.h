#pragma once

#include "S_ActorAnimRequest.h"
#include "S_ActionRequestImpl.h"

namespace wh::entitymodule {

struct S_ActorAnimRequestImpl : S_ActionRequestImpl<S_ActorAnimRequest> {
    ~S_ActorAnimRequestImpl() override;                     // [0] 0x1808E2274
    bool unk_01(void* output) const override;               // [1] 0x18039DCB4, builds actor-animation query data
    RTTR_ENABLE(S_ActionRequestImpl<S_ActorAnimRequest>)     // [4..6], vtable 0x183A5DA10
};

static_assert(sizeof(S_ActorAnimRequestImpl) == 0x208,
              "S_ActorAnimRequestImpl size mismatch");

}  // namespace wh::entitymodule
