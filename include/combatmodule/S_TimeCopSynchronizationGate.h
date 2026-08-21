#pragma once
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <Windows.h>

namespace wh::combatmodule {

struct S_TimeCopSynchronizationGate {
    std::atomic<std::int32_t> m_activeReaders;   // +0x00
    std::atomic<std::int32_t> m_waitingWriters;  // +0x04
    HANDLE                    m_readersDrainedEvent; // +0x08, owned
    SRWLOCK                   m_writerLock;      // +0x10
    std::int32_t              m_writerRecursion; // +0x18
    DWORD                     m_writerThreadId;  // +0x1C
};
static_assert(sizeof(S_TimeCopSynchronizationGate) == 0x20);
static_assert(offsetof(S_TimeCopSynchronizationGate, m_activeReaders) == 0x00);
static_assert(offsetof(S_TimeCopSynchronizationGate, m_readersDrainedEvent) == 0x08);
static_assert(offsetof(S_TimeCopSynchronizationGate, m_writerLock) == 0x10);
static_assert(offsetof(S_TimeCopSynchronizationGate, m_writerRecursion) == 0x18);

}  // namespace wh::combatmodule
