#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::shared {

// Synthetic source-like name for the reusable non-polymorphic delegate storage
// dispatched by 0x1803A524C.
struct S_MulticastDelegateStorage {
    void* m_pEntries;                       // +0x00, COW entries {target, member-call thunk}
    std::int16_t m_dispatchCursor[2];       // +0x08, -1 when the dispatch level is free
    std::uint8_t _pad0C[4];                 // +0x0C
};
static_assert(sizeof(S_MulticastDelegateStorage) == 0x10,
              "S_MulticastDelegateStorage must be 0x10");
static_assert(offsetof(S_MulticastDelegateStorage, m_dispatchCursor) == 0x08,
              "dispatch cursors must be at 0x08");

}  // namespace wh::shared
