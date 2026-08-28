#pragma once

#include <cstddef>

namespace wh::entitymodule {

// Source name unresolved; deque consumers prove this two-qword queue record.
struct S_ClothingSystemQueueEntry {
    void* m_object;                                         // +0x00, borrowed polymorphic object
    double m_timestamp;                                     // +0x08
};

static_assert(offsetof(S_ClothingSystemQueueEntry, m_timestamp) == 0x08,
              "S_ClothingSystemQueueEntry::m_timestamp offset mismatch");
static_assert(sizeof(S_ClothingSystemQueueEntry) == 0x10,
              "S_ClothingSystemQueueEntry size mismatch");

}  // namespace wh::entitymodule
