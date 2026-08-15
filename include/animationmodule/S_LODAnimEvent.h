#pragma once
#include <cstddef>
#include <cstdint>
#include "S_LODAnimEventData.h"
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::animationmodule {

// Source-reconstructed name; exact 0x68 scheduled LOD animation-event record.
struct S_LODAnimEvent {
    float m_eventTime;                  // +0x00
    std::int32_t m_animationId;         // +0x04
    CryStringT<char> m_animationName;   // +0x08
    S_LODAnimEventData m_eventData;     // +0x10
    std::int32_t m_state;               // +0x60, observed 0/2/5; full domain OPEN
    std::uint32_t _pad64;               // +0x64
};
static_assert(sizeof(S_LODAnimEvent) == 0x68,
              "LOD animation event must be 0x68");
static_assert(offsetof(S_LODAnimEvent, m_eventData) == 0x10,
              "LOD animation-event data must be at 0x10");
static_assert(offsetof(S_LODAnimEvent, m_state) == 0x60,
              "LOD animation-event state must be at 0x60");

}  // namespace wh::animationmodule
