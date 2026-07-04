#pragma once
#include <cstdint>
#include "I_InputStream.h"
#include "I_MemoryOutputStream.h"

// -----------------------------------------------
// wh::shared::C_FragmentedMemoryIOStream -- chunked in-memory IO stream (KCD2 1.5.6, kd7u).
// sizeof 0x38.
// -----------------------------------------------
// Dual-vtable sibling of C_MemoryIOStream: output chain @+0x00 vtable 0x183A531A0,
// I_InputStream @+0x08 vtable 0x183A53138. Ctor sub_180794E64(this, chunkSize, totalSize);
// dtor sub_180794EF0. Instead of one contiguous buffer it keeps a heap-allocated chunk
// vector ({begin,end,cap} triple) behind the +0x10 pointer.

namespace wh::shared {

class C_FragmentedMemoryIOStream : public I_MemoryOutputStream, public I_InputStream {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FragmentedMemoryIOStream;
    void*    m_pChunkVec;   // +0x10  heap {begin,end,cap} of chunk pointers (indirect vector)
    uint64_t m_chunkSize;   // +0x18  ctor arg2
    uint64_t m_unk20;       // +0x20  ctor 0 [position/state split UNPINNED]
    uint64_t m_unk28;       // +0x28  ctor 0 [ditto]
    uint64_t m_unk30;       // +0x30  ctor 0 [ditto]
};
static_assert(sizeof(C_FragmentedMemoryIOStream) == 0x38, "C_FragmentedMemoryIOStream must be 0x38");

}  // namespace wh::shared
