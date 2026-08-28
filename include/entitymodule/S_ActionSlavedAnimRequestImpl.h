#pragma once
#include "S_ActionAnimRequestImpl.h"

namespace wh::entitymodule {

template <typename TRequest>
struct S_ActionSlavedAnimRequestImpl : S_ActionAnimRequestImpl<TRequest> {
    ~S_ActionSlavedAnimRequestImpl() override;                   // [0] 0x1828B1238
    RTTR_ENABLE(S_ActionAnimRequestImpl<TRequest>)               // [4..6]
};

static_assert(
    sizeof(S_ActionSlavedAnimRequestImpl<S_ActionSlavedAnimRequest>) == 0x100,
    "S_ActionSlavedAnimRequestImpl specialization size mismatch");

}  // namespace wh::entitymodule
