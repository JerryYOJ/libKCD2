#pragma once
#include "S_ActionRequestImpl.h"

namespace wh::entitymodule {

template <typename TRequest>
struct S_ActionAnimRequestImpl : S_ActionRequestImpl<TRequest> {
    ~S_ActionAnimRequestImpl() override;
    RTTR_ENABLE(S_ActionRequestImpl<TRequest>)                   // [4..6]
};

static_assert(sizeof(S_ActionAnimRequestImpl<S_ActionAdditiveAnimRequest>) == 0xF8,
              "S_ActionAnimRequestImpl<S_ActionAdditiveAnimRequest> size mismatch");
static_assert(sizeof(S_ActionAnimRequestImpl<S_ActionFullBodyAnimRequest>) == 0xF8,
              "S_ActionAnimRequestImpl<S_ActionFullBodyAnimRequest> size mismatch");
static_assert(sizeof(S_ActionAnimRequestImpl<S_ActionSlavedAnimRequest>) == 0x100,
              "S_ActionAnimRequestImpl<S_ActionSlavedAnimRequest> size mismatch");

}  // namespace wh::entitymodule
