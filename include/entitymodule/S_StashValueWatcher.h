#pragma once
#include <cstdint>

namespace wh::entitymodule {

// Synthetic type name; exact inline ABI is reused by Stash and NPC value tracking.
struct S_StashValueWatcher {
    float m_robbedValue;        // +0x00, serialized as RobbedValue
    float m_onOpenValue;        // +0x04, serialized as OnOpenValue
    float m_decayRate;          // +0x08, owner-specific robbed-value decay rate
    float m_bottomThreshold;    // +0x0C, owner-specific bottom threshold
    std::int64_t m_timestamp;   // +0x10, serialized as Timestamp
};
static_assert(sizeof(S_StashValueWatcher) == 0x18,
              "S_StashValueWatcher must be 0x18");

}  // namespace wh::entitymodule
