#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "S_ActionRequest.h"

namespace wh::entitymodule {

struct S_ActionAnimRequest : S_ActionRequest {
    ~S_ActionAnimRequest() override;                            // [0] 0x1828954DC
    RTTR_ENABLE(S_ActionRequest)                                // [4..6]

    std::uint64_t m_unknown48;                                 // +0x48
    std::uint32_t m_unknown50;                                 // +0x50
    float m_playbackScale;                                     // +0x54, initialized to 1.0
    Vec3 m_unknown58;                                          // +0x58
    std::uint32_t m_padding64;                                 // +0x64
    std::function<void()> m_callback68;                        // +0x68, callable signature OPEN
    std::function<void()> m_callbackA8;                        // +0xA8, callable signature OPEN
};

static_assert(offsetof(S_ActionAnimRequest, m_unknown48) == 0x48,
              "S_ActionAnimRequest::m_unknown48 offset mismatch");
static_assert(offsetof(S_ActionAnimRequest, m_playbackScale) == 0x54,
              "S_ActionAnimRequest::m_playbackScale offset mismatch");
static_assert(offsetof(S_ActionAnimRequest, m_callback68) == 0x68,
              "S_ActionAnimRequest::m_callback68 offset mismatch");
static_assert(offsetof(S_ActionAnimRequest, m_callbackA8) == 0xA8,
              "S_ActionAnimRequest::m_callbackA8 offset mismatch");
static_assert(sizeof(S_ActionAnimRequest) == 0xE8,
              "S_ActionAnimRequest size mismatch");

}  // namespace wh::entitymodule
