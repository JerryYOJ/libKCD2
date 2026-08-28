#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <vector>

#include "../framework/I_ReadinessTask.h"
#include "../rttr/rttr_enable.h"
#include "I_ClothingSystem.h"
#include "S_ClothingSystemCursor.h"
#include "S_ClothingSystemQueueEntry.h"
#include "S_ClothingSystemStorage.h"

namespace wh::entitymodule {

class C_ClothingSystem : public I_ClothingSystem, public wh::I_ReadinessTask {
public:
    ~C_ClothingSystem() override;                          // Primary [0] 0x1829173F8
    void unk_01() override;                                // Primary [1] 0x180666864
    void unk_02() override;                                // Primary [2] 0x180C205BC
    RTTR_ENABLE()                                           // Primary [3..5], vtable 0x183E8B8A8

    bool TaskVf2() override;                               // Secondary [2] 0x1814D8714
    std::uint32_t TaskVf3() override;                      // Secondary [3] 0x181A846F0
    const void* TaskVf4() override;                        // Secondary [4] 0x181A84700

    std::array<std::deque<S_ClothingSystemQueueEntry*>, 5> m_queues; // +0x10
    std::array<std::uint64_t, 5> m_queueState;             // +0xD8
    S_ClothingSystemStorage m_storage;                     // +0x100
    void* m_queueOwner;                                    // +0x168, points to +0x10
    std::uint64_t m_cursorSentinel;                        // +0x170
    S_ClothingSystemCursor m_cursor;                       // +0x178
    std::vector<void*> m_items;                            // +0x198, borrowed polymorphic records
    bool m_forceSort;                                      // +0x1B0
    std::uint8_t m_padding1B1[7];                          // +0x1B1
    void* m_pendingTask;                                   // +0x1B8, owned polymorphic type unresolved
    float m_readiness;                                     // +0x1C0, initialized -1.0
    std::uint32_t m_pendingCount;                          // +0x1C4
};

static_assert(sizeof(std::deque<S_ClothingSystemQueueEntry*>) == 0x28,
              "MSVC deque layout mismatch");
static_assert(offsetof(C_ClothingSystem, m_queues) == 0x10,
              "C_ClothingSystem::m_queues offset mismatch");
static_assert(offsetof(C_ClothingSystem, m_queueState) == 0xD8,
              "C_ClothingSystem::m_queueState offset mismatch");
static_assert(offsetof(C_ClothingSystem, m_storage) == 0x100,
              "C_ClothingSystem::m_storage offset mismatch");
static_assert(offsetof(C_ClothingSystem, m_cursor) == 0x178,
              "C_ClothingSystem::m_cursor offset mismatch");
static_assert(offsetof(C_ClothingSystem, m_items) == 0x198,
              "C_ClothingSystem::m_items offset mismatch");
static_assert(offsetof(C_ClothingSystem, m_pendingTask) == 0x1B8,
              "C_ClothingSystem::m_pendingTask offset mismatch");
static_assert(sizeof(C_ClothingSystem) == 0x1C8,
              "C_ClothingSystem size mismatch");

}  // namespace wh::entitymodule
