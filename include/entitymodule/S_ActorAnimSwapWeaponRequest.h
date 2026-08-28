#pragma once
#include <cstddef>
#include <cstdint>
#include "S_ActionFullBodyAnimRequest.h"

namespace wh::entitymodule {

struct S_ActorAnimSwapWeaponRequest : S_ActionFullBodyAnimRequest {
    ~S_ActorAnimSwapWeaponRequest() override;                   // [0] 0x1828B1694
    RTTR_ENABLE(S_ActionFullBodyAnimRequest)                    // [4..6]

    std::uint32_t m_unknownE8;                                 // +0xE8, initialized to 3
    std::uint32_t m_paddingEC;                                 // +0xEC
    std::uint64_t m_unknownF0;                                 // +0xF0
    std::uint64_t m_unknownF8;                                 // +0xF8
    std::uint32_t m_unknown100;                                // +0x100
    bool m_unknown104;                                         // +0x104
    std::uint8_t m_padding105[3];                              // +0x105
    bool m_unknown108;                                         // +0x108
    std::uint8_t m_padding109[7];                              // +0x109
};

static_assert(offsetof(S_ActorAnimSwapWeaponRequest, m_unknownE8) == 0xE8,
              "S_ActorAnimSwapWeaponRequest::m_unknownE8 offset mismatch");
static_assert(offsetof(S_ActorAnimSwapWeaponRequest, m_unknownF0) == 0xF0,
              "S_ActorAnimSwapWeaponRequest::m_unknownF0 offset mismatch");
static_assert(offsetof(S_ActorAnimSwapWeaponRequest, m_unknown108) == 0x108,
              "S_ActorAnimSwapWeaponRequest::m_unknown108 offset mismatch");
static_assert(sizeof(S_ActorAnimSwapWeaponRequest) == 0x110,
              "S_ActorAnimSwapWeaponRequest size mismatch");

}  // namespace wh::entitymodule
