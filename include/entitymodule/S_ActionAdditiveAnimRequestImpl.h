#pragma once
#include "S_ActionAnimRequestImpl.h"

namespace wh::entitymodule {

template <typename TRequest>
struct S_ActionAdditiveAnimRequestImpl : S_ActionAnimRequestImpl<TRequest> {
    ~S_ActionAdditiveAnimRequestImpl() override;                 // [0] 0x1816E9544
    RTTR_ENABLE(S_ActionAnimRequestImpl<TRequest>)               // [4..6]
};

static_assert(
    sizeof(S_ActionAdditiveAnimRequestImpl<S_ActionAdditiveAnimRequest>) == 0xF8,
    "S_ActionAdditiveAnimRequestImpl specialization size mismatch");

}  // namespace wh::entitymodule
