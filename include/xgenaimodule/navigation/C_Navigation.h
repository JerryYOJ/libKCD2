#pragma once
#include <cstdint>
#include "I_Navigation.h"
#include "I_MNMOverride.h"
#include "C_PathFinder.h"
#include "C_NavigationElementWalkBase.h"
#include "C_PathManager.h"
#include "C_ReplanMoveAreaRegistry.h"

// -----------------------------------------------
// wh::xgenaimodule::navigation::C_Navigation -- Recast/Detour navmesh system
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x1C0.
// -----------------------------------------------
// RTTI .?AVC_Navigation@navigation@xgenaimodule@wh@@.  Primary vtable 0x18400C3F8
// (42 I_Navigation slots), secondary 0x18400C550 (I_MNMOverride @+0x08).
// ctor sub_180D39C78, alloc 448 (C_XGenAIModule Init). Owned at
// C_XGenAIModule+0x78. Deepens the earlier 13-slot shell.

namespace wh::xgenaimodule::navigation {

class C_Navigation : public I_Navigation, public I_MNMOverride {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Navigation;

    uint32_t DefaultNavMeshId() const
    {
        uint32_t id = 0;
        GetDefaultNavMeshId(&id);
        return id;
    }

    uint8_t      _pad10[0x78];                              // +0x10
    uint32_t     m_defaultNavMeshId;                        // +0x88
    uint32_t     _pad8C;                                    // +0x8C
    uint8_t      _pad90[0xB8];                              // +0x90
    C_PathManager* m_pPathManager;                          // +0x148
    C_PathFinder* m_pPathFinder;                            // +0x150
    uint8_t      _pad158[0x20];                             // +0x158
    C_ReplanMoveAreaRegistry* m_pReplanMoveAreaRegistry;    // +0x178
    uint8_t      _pad180[0x40];                             // +0x180
};
static_assert(sizeof(C_Navigation) == 0x1C0, "C_Navigation must be 0x1C0 (alloc 448)");
static_assert(offsetof(C_Navigation, m_defaultNavMeshId) == 0x88, "default mesh id at +0x88");
static_assert(offsetof(C_Navigation, m_pPathManager) == 0x148, "path manager at +0x148");
static_assert(offsetof(C_Navigation, m_pPathFinder) == 0x150, "pathfinder at +0x150");
static_assert(offsetof(C_Navigation, m_pReplanMoveAreaRegistry) == 0x178, "replan registry at +0x178");

}  // namespace wh::xgenaimodule::navigation
