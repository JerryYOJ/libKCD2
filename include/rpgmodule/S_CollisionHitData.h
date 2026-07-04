#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::S_CollisionHitData -- payload of C_CollisionHitCause (KCD2 WHGame.dll
// 1.5.6, kd7u).
// -----------------------------------------------
// sizeof 0x68 (PROVEN: ctor sub_1816C7BB4 tracked-alloc 112 = 8+104, bulk copy
// @0x1816C7C17..C48).  Create-site sub_1816C79F8 treats the source as two symmetric
// 32-byte "hit participant" records (A @+0x00, B @+0x20) and raises two events with A/B
// swapped; per-byte naming of the records is UNVERIFIED.

namespace wh::rpgmodule {

struct S_CollisionHitData {
    uint8_t  m_blkA[16];    // +0x00  participant-A lead block [U]
    uint64_t m_idA;         // +0x10  qword id (create-site reads a3+16) [proposed]
    int32_t  m_iA;          // +0x18  int32 (a3+24) [U role]
    uint8_t  _pad1C[4];     // +0x1C
    uint8_t  m_blkB[16];    // +0x20  participant-B lead block [U]
    uint64_t m_idB;         // +0x30  qword id (a3+48) [proposed]
    int32_t  m_iB;          // +0x38  int32 (a3+56) [U role]
    uint8_t  m_tail[44];    // +0x3C  copied but not individually referenced [U]
};
static_assert(sizeof(S_CollisionHitData) == 0x68, "S_CollisionHitData must be 0x68 (alloc 112 minus vptr)");

}  // namespace wh::rpgmodule
