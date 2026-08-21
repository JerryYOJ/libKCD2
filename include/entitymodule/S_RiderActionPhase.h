#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::entitymodule::S_RiderActionPhase -- KCD2 WHGame.dll.  sizeof 0x18.
// -----------------------------------------------
// [SYNTHETIC] no TypeDescriptor. Factory sub_180AD3F64 alloc 0x18.
// Lives at C_ActorActionRider+0x90 / C_RiderSync+0x20.
// +0x08 is the phase id (0/1/2/3/4/5/6/0xA) via sub_1829F2878 / sub_180AD29B8.

namespace wh::entitymodule {

class C_ActorActionRider;

class S_RiderActionPhase {
public:
    C_ActorActionRider* m_pAction;   // +0x00
    uint8_t             m_phase;     // +0x08
    uint8_t             m_b09;       // +0x09
    uint8_t             m_b0A;       // +0x0A
    uint8_t             m_flag0B;    // +0x0B  ctor 1 (dword +8 = 0x01000000)
    uint32_t            _pad0C;      // +0x0C
    uint64_t            m_zero10;    // +0x10
};
static_assert(sizeof(S_RiderActionPhase) == 0x18, "S_RiderActionPhase must be 0x18");
static_assert(offsetof(S_RiderActionPhase, m_phase) == 0x08, "phase");

}  // namespace wh::entitymodule
