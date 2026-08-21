#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::entitymodule::S_RiderSyncAnim -- KCD2 WHGame.dll.  sizeof 0x18.
// -----------------------------------------------
// [SYNTHETIC] no TypeDescriptor. Heap from C_RiderSync ctor (a5/a6 bytes).
// I_HorseRiderSync[18] reads +0x10.

namespace wh::entitymodule {

class C_RiderSync;

class S_RiderSyncAnim {
public:
    C_RiderSync* m_pSync;     // +0x00
    float        m_blend;     // +0x08  -1.0
    int32_t      m_negOne;    // +0x0C  -1
    uint8_t      m_flag10;    // +0x10  factory a5
    uint8_t      m_flag11;    // +0x11  factory a6
    uint8_t      _pad12[6];   // +0x12
};
static_assert(sizeof(S_RiderSyncAnim) == 0x18, "S_RiderSyncAnim must be 0x18");
static_assert(offsetof(S_RiderSyncAnim, m_flag10) == 0x10, "flag10");

}  // namespace wh::entitymodule
