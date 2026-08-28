#pragma once

#include "S_ActionFullBodyAnimRequestImpl.h"
#include "S_ActionIdleRequest.h"

namespace wh::entitymodule {

struct S_ActionIdleRequestImpl
    : S_ActionFullBodyAnimRequestImpl<S_ActionIdleRequest> {
    ~S_ActionIdleRequestImpl() override;                       // [0] 0x181945590
    RTTR_ENABLE(S_ActionFullBodyAnimRequestImpl<S_ActionIdleRequest>) // [4..6], vtable 0x183C14788
};

static_assert(sizeof(S_ActionIdleRequestImpl) == 0x100,
              "S_ActionIdleRequestImpl size mismatch");

}  // namespace wh::entitymodule
