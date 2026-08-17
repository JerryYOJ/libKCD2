#pragma once
#include <cstddef>
#include <cstdint>

// Auxiliary current-hit context; canonical native type name remains open.
struct SHitAuxContext {
    void* m_retainedObject;           // +0x00, retained through its virtual AddRef/Release surface
    const void* m_pValueSource;       // +0x08, optional dword source
    std::uint64_t m_identity;         // +0x10, exact identity type OPEN
    std::int32_t m_unknown18;         // +0x18, default -1
    std::int32_t m_unknown1C;         // +0x1C, default -1
    std::int32_t m_unknown20;         // +0x20, default 0
    std::byte m_open24[0x04];         // +0x24
};
static_assert(sizeof(SHitAuxContext) == 0x28,
              "SHitAuxContext must be 0x28");
static_assert(offsetof(SHitAuxContext, m_identity) == 0x10,
              "hit auxiliary identity must be at 0x10");
