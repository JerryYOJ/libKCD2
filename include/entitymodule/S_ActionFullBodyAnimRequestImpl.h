#pragma once
#include "S_ActionAnimRequestImpl.h"

namespace wh::entitymodule {

template <typename TRequest>
struct S_ActionFullBodyAnimRequestImpl : S_ActionAnimRequestImpl<TRequest> {
    ~S_ActionFullBodyAnimRequestImpl() override;                 // [0] 0x1816E9544
    RTTR_ENABLE(S_ActionAnimRequestImpl<TRequest>)               // [4..6]
};

static_assert(
    sizeof(S_ActionFullBodyAnimRequestImpl<S_ActionFullBodyAnimRequest>) == 0xF8,
    "S_ActionFullBodyAnimRequestImpl specialization size mismatch");

}  // namespace wh::entitymodule
