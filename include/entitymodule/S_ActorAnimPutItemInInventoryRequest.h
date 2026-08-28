#pragma once
#include <cstddef>
#include <cstdint>
#include "S_ActionFullBodyAnimRequest.h"

namespace wh::entitymodule {

struct S_ActorAnimPutItemInInventoryRequest : S_ActionFullBodyAnimRequest {
    ~S_ActorAnimPutItemInInventoryRequest() override;           // [0] 0x1828B15E8
    RTTR_ENABLE(S_ActionFullBodyAnimRequest)                    // [4..6]

    std::uint32_t m_unknownE8;                                 // +0xE8, initialized to 2
    std::uint32_t m_paddingEC;                                 // +0xEC
    std::uint64_t m_unknownF0;                                 // +0xF0
};

static_assert(offsetof(S_ActorAnimPutItemInInventoryRequest, m_unknownE8) == 0xE8,
              "S_ActorAnimPutItemInInventoryRequest::m_unknownE8 offset mismatch");
static_assert(offsetof(S_ActorAnimPutItemInInventoryRequest, m_unknownF0) == 0xF0,
              "S_ActorAnimPutItemInInventoryRequest::m_unknownF0 offset mismatch");
static_assert(sizeof(S_ActorAnimPutItemInInventoryRequest) == 0xF8,
              "S_ActorAnimPutItemInInventoryRequest size mismatch");

}  // namespace wh::entitymodule
