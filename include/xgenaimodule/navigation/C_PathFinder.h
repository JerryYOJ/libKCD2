#pragma once
#include <cstdint>
#include <vector>
#include "I_PathFinder.h"

// -----------------------------------------------
// wh::xgenaimodule::navigation::C_PathFinder -- Recast/Detour pathfinder
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x1C0.
// -----------------------------------------------
// RTTI .?AVC_PathFinder@navigation@xgenaimodule@wh@@.  vtable 0x18400CC20, 4 slots
// matching I_PathFinder. ctor sub_180D3A840 (alloc 448). Owned at
// C_Navigation+0x150. Registers `wh_ai_PathFinderEnabled` and
// `wh_ai_PathFinderCenterPosChangeThresholdSQ` (float at +0x1B0).
// Validator sub_180879D00 reads the pointer array at +0x88/+0x90.

namespace wh::xgenaimodule::navigation {

class C_PathFinder : public I_PathFinder {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PathFinder;

    uint8_t _pad08[0x80];                                   // +0x08
    std::vector<void*> m_navMeshes;                         // +0x88  pointer array the validator indexes [elem UNVERIFIED]
    uint8_t _padA0[0x110];                                  // +0xA0
    float   m_centerPosChangeThresholdSq;                   // +0x1B0  CVar wh_ai_PathFinderCenterPosChangeThresholdSQ
    uint8_t _pad1B4[0x0C];                                  // +0x1B4
};
static_assert(sizeof(C_PathFinder) == 0x1C0, "C_PathFinder must be 0x1C0 (alloc 448)");
static_assert(offsetof(C_PathFinder, m_navMeshes) == 0x88, "navmesh slot table at +0x88");
static_assert(offsetof(C_PathFinder, m_centerPosChangeThresholdSq) == 0x1B0, "threshold CVar at +0x1B0");

}  // namespace wh::xgenaimodule::navigation
