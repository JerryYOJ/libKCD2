#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::playermodule::S_MinigameHandleSlot -- sentinel-backed manager record
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x10. [SYNTHETIC NAME]
// -----------------------------------------------
// Initializer sub_180EF7360 stores the static sentinel pointer and two -1
// 16-bit values. The role and final four bytes remain unresolved.

namespace wh::playermodule {

struct S_MinigameHandleSlot {
    void*    m_pSentinel; // +0x00  &unk_1856681D0
    int16_t  m_index;     // +0x08  initialized -1
    int16_t  m_generation; // +0x0A  initialized -1
    uint8_t  _pad0C[4];   // +0x0C  role/open state unresolved
};
static_assert(sizeof(S_MinigameHandleSlot) == 0x10,
              "S_MinigameHandleSlot must preserve the 0x10 manager stride");
static_assert(offsetof(S_MinigameHandleSlot, m_generation) == 0x0A,
              "generation sentinel must be at +0x0A");

}  // namespace wh::playermodule
