#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::S_ProfilingLogPayload -- 0x30-byte payload block of C_ProfilingLogEffect
// (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// NAME INVENTED (no TypeDescriptor; real name unknown).  Layout PROVEN by its copy-helper
// sub_1812C2FE8: {data, count, capacity} dynamic buffer of 16-byte elements (raw allocator
// sub_1804F75C0(16*count)) + 0x18 tail bytes copied verbatim; dtor sub_1804BF0C0 destroys
// elements then frees when capacity != 0.  [element/tail semantics UNVERIFIED]

namespace wh::rpgmodule {

struct S_ProfilingLogPayload {
    void*    m_pData;      // +0x00  heap buffer of 16-byte elements
    uint64_t m_count;      // +0x08
    uint64_t m_capacity;   // +0x10  0 => not owning
    uint64_t m_unk18;      // +0x18  copied verbatim
    uint64_t m_unk20;      // +0x20  copied verbatim
    uint32_t m_unk28;      // +0x28  copied verbatim
    // +0x2C 4-byte tail padding
};
static_assert(sizeof(S_ProfilingLogPayload) == 0x30, "S_ProfilingLogPayload must be 0x30");

}  // namespace wh::rpgmodule
