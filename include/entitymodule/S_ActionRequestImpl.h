#pragma once
#include <cstddef>
#include <cstdint>
#include "S_ActionAdditiveAnimRequest.h"
#include "S_ActionFullBodyAnimRequest.h"
#include "S_ActionSlavedAnimRequest.h"
#include "S_ActorAnimDrawRequest.h"
#include "S_ActorAnimDropRequest.h"
#include "S_ActorAnimHolsterRequest.h"
#include "S_ActorAnimPickUpRequest.h"
#include "S_ActorAnimPlaceRequest.h"
#include "S_ActorAnimPutItemInHandRequest.h"
#include "S_ActorAnimPutItemInInventoryRequest.h"
#include "S_ActorAnimSwapWeaponRequest.h"

namespace wh::entitymodule {

template <typename TRequest>
struct S_ActionRequestImpl : TRequest {
    ~S_ActionRequestImpl() override;
    bool unk_01(void* output) const override;                    // [1], writes m_actionTypeId at output +0x08
    std::uint32_t unk_02() const override;                       // [2], returns m_unknown04
    std::uint8_t unk_03() const override;                        // [3], returns m_unknown08
    RTTR_ENABLE(TRequest)                                        // [4..6]

    std::uint32_t m_actionTypeId;                               // +sizeof(TRequest)
    std::uint32_t m_unknown04;
    std::uint8_t m_unknown08;
    std::uint8_t m_padding09[7];
};

static_assert(offsetof(
                  S_ActionRequestImpl<S_ActionAdditiveAnimRequest>,
                  m_actionTypeId) == 0xE8,
              "S_ActionRequestImpl additive tail offset mismatch");
static_assert(offsetof(
                  S_ActionRequestImpl<S_ActorAnimDrawRequest>,
                  m_actionTypeId) == 0x130,
              "S_ActionRequestImpl draw tail offset mismatch");
static_assert(sizeof(S_ActionRequestImpl<S_ActionAdditiveAnimRequest>) == 0xF8,
              "S_ActionRequestImpl<S_ActionAdditiveAnimRequest> size mismatch");
static_assert(sizeof(S_ActionRequestImpl<S_ActionFullBodyAnimRequest>) == 0xF8,
              "S_ActionRequestImpl<S_ActionFullBodyAnimRequest> size mismatch");
static_assert(sizeof(S_ActionRequestImpl<S_ActionSlavedAnimRequest>) == 0x100,
              "S_ActionRequestImpl<S_ActionSlavedAnimRequest> size mismatch");
static_assert(sizeof(S_ActionRequestImpl<S_ActorAnimHolsterRequest>) == 0xF8,
              "S_ActionRequestImpl<S_ActorAnimHolsterRequest> size mismatch");
static_assert(sizeof(S_ActionRequestImpl<S_ActorAnimDropRequest>) == 0x100,
              "S_ActionRequestImpl<S_ActorAnimDropRequest> size mismatch");
static_assert(sizeof(S_ActionRequestImpl<S_ActorAnimPickUpRequest>) == 0x118,
              "S_ActionRequestImpl<S_ActorAnimPickUpRequest> size mismatch");
static_assert(sizeof(S_ActionRequestImpl<S_ActorAnimPlaceRequest>) == 0x118,
              "S_ActionRequestImpl<S_ActorAnimPlaceRequest> size mismatch");
static_assert(sizeof(S_ActionRequestImpl<S_ActorAnimPutItemInHandRequest>) == 0x108,
              "S_ActionRequestImpl<S_ActorAnimPutItemInHandRequest> size mismatch");
static_assert(sizeof(S_ActionRequestImpl<S_ActorAnimPutItemInInventoryRequest>) == 0x108,
              "S_ActionRequestImpl<S_ActorAnimPutItemInInventoryRequest> size mismatch");
static_assert(sizeof(S_ActionRequestImpl<S_ActorAnimSwapWeaponRequest>) == 0x120,
              "S_ActionRequestImpl<S_ActorAnimSwapWeaponRequest> size mismatch");
static_assert(sizeof(S_ActionRequestImpl<S_ActorAnimDrawRequest>) == 0x140,
              "S_ActionRequestImpl<S_ActorAnimDrawRequest> size mismatch");

}  // namespace wh::entitymodule
