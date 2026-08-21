#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>
#include "../framework/CryDeferrable.h"
#include "I_HorseRiderSync.h"
#include "S_RiderActionPhase.h"
#include "S_RiderSyncAnim.h"

// -----------------------------------------------
// wh::entitymodule::C_RiderSync -- KCD2 WHGame.dll.  sizeof 0x58.
// -----------------------------------------------
// RTTI : I_HorseRiderSync @0, CryDeferrableSlot @8.
// Factory sub_181EC4FD0 (alloc 0x58), ctor sub_181ECA1F0.
// a2 = rider, a3 = horse, a4 = S_RiderActionPhase* (action+0x90).

namespace wh::entitymodule {

class C_Actor;

class C_RiderSync : public I_HorseRiderSync {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RiderSync;
    UnsafeOp::CryDeferrableSlot m_defer;     // +0x08
    uint8_t                     m_flags18;   // +0x18  bit0 live/mounted
    uint8_t                     _pad19[3];   // +0x19
    uint32_t                    m_zero1C;    // +0x1C  ctor 0
    S_RiderActionPhase*         m_pPhase;    // +0x20
    C_Actor*                    m_pRider;    // +0x28  GetRider
    C_Actor*                    m_pHorse;    // +0x30  GetHorse
    S_RiderSyncAnim*            m_pAnim;     // +0x38
    std::vector<uint64_t>       m_tagPairs;  // +0x40
};
static_assert(sizeof(C_RiderSync) == 0x58, "C_RiderSync must be 0x58");
static_assert(offsetof(C_RiderSync, m_pPhase) == 0x20, "phase");
static_assert(offsetof(C_RiderSync, m_pRider) == 0x28, "rider");
static_assert(offsetof(C_RiderSync, m_pHorse) == 0x30, "horse");
static_assert(offsetof(C_RiderSync, m_tagPairs) == 0x40, "tag vector");

}  // namespace wh::entitymodule
