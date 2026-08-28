#pragma once
#include "S_ActionRequestImpl.h"

namespace wh::entitymodule {

template <typename TRequest>
struct S_ActorAnimItemHandlingRequestImpl : S_ActionRequestImpl<TRequest> {
    ~S_ActorAnimItemHandlingRequestImpl() override;
    RTTR_ENABLE(S_ActionRequestImpl<TRequest>)                   // [4..6]
};

static_assert(sizeof(
                  S_ActorAnimItemHandlingRequestImpl<S_ActorAnimHolsterRequest>) ==
                  0xF8,
              "item-handling holster specialization size mismatch");
static_assert(sizeof(
                  S_ActorAnimItemHandlingRequestImpl<S_ActorAnimDropRequest>) ==
                  0x100,
              "item-handling drop specialization size mismatch");
static_assert(sizeof(
                  S_ActorAnimItemHandlingRequestImpl<S_ActorAnimPickUpRequest>) ==
                  0x118,
              "item-handling pick-up specialization size mismatch");
static_assert(sizeof(
                  S_ActorAnimItemHandlingRequestImpl<S_ActorAnimPlaceRequest>) ==
                  0x118,
              "item-handling place specialization size mismatch");
static_assert(sizeof(
                  S_ActorAnimItemHandlingRequestImpl<
                      S_ActorAnimPutItemInHandRequest>) == 0x108,
              "item-handling put-in-hand specialization size mismatch");
static_assert(sizeof(
                  S_ActorAnimItemHandlingRequestImpl<
                      S_ActorAnimPutItemInInventoryRequest>) == 0x108,
              "item-handling put-in-inventory specialization size mismatch");
static_assert(sizeof(
                  S_ActorAnimItemHandlingRequestImpl<S_ActorAnimSwapWeaponRequest>) ==
                  0x120,
              "item-handling swap-weapon specialization size mismatch");
static_assert(sizeof(
                  S_ActorAnimItemHandlingRequestImpl<S_ActorAnimDrawRequest>) ==
                  0x140,
              "item-handling draw specialization size mismatch");

}  // namespace wh::entitymodule
