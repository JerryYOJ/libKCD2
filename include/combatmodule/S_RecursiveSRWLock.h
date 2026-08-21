#pragma once
#include <cstddef>
#include <cstdint>
#include <Windows.h>

namespace wh::combatmodule {

struct S_RecursiveSRWLock {
    SRWLOCK       m_lock;          // +0x00
    std::uint32_t m_recursion;     // +0x08
    std::uint32_t m_ownerThreadId; // +0x0C
};
static_assert(sizeof(S_RecursiveSRWLock) == 0x10);
static_assert(offsetof(S_RecursiveSRWLock, m_lock) == 0x00);
static_assert(offsetof(S_RecursiveSRWLock, m_recursion) == 0x08);
static_assert(offsetof(S_RecursiveSRWLock, m_ownerThreadId) == 0x0C);

}  // namespace wh::combatmodule
