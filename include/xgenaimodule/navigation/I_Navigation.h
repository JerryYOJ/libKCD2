#pragma once
#include <cstdint>
#include "I_PathFinder.h"
#include "S_PathFindingResult.h"
#include "S_NavMeshSource.h"
#include "../../framework/C_Listeners.h"   // wh::shared::C_Listeners

// -----------------------------------------------
// wh::xgenaimodule::navigation::I_Navigation -- navmesh system contract
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x08.
// -----------------------------------------------
// RTTI .?AVI_Navigation@navigation@xgenaimodule@wh@@.  Interface vtable
// 0x18400C5D0, 42 slots (0-41; slot 42 is the next COL). C_Navigation implements
// this as its primary base. Only the path-query cluster is named.

// Detour navmesh (WH kept dt* spellings: RTTI .?AUdtTileCacheAlloc@navigation@...)
class dtNavMesh;

namespace wh::xgenaimodule::navigation {

class C_PathManager;
class C_ReplanMoveAreaRegistry;
class C_TileCacheUpdateManager;   // 0xC8 obj at runtime-agent +0x60 (cvar wh_ai_TileCacheAsBuildBuffer)
// not-yet-RE'd nav subsystems (pointer/ref-only use here)
class I_ReplanMovesNotify;
class C_PathSpeedLimiter;
class C_MovementTaskManager;
class C_NavMeshObstacleManager;
class C_OffMeshLinksManager;
class I_RayCastHelper;
struct S_NavigationAgentContext;
struct S_NavMeshQueryContext;
struct S_EngineNavigationAgent;

// agent-type handle: sequential 1-based id from mnm-settings parser 0x1811D1E8C [INFERRED]
using NavigationAgentTypeID = std::uint32_t;

// [INFERRED spelling] 0x14 cylinder consumed by converter 0x180D33260
struct S_NavigationObstacleCylinder {
    Vec3  base;     // +0x00
    float radius;   // +0x0C
    float height;   // +0x10
};

class I_Navigation {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_Navigation;
    virtual ~I_Navigation() = default;                      // [0]
    virtual C_PathManager* GetPathManager() = 0;            // [1] 0x181A76BE0  this+0x148
    virtual bool ReloadConfig() = 0;
    virtual void BlockObstacleArea(const S_NavigationObstacleCylinder& obstacle) = 0;
    virtual void UnblockObstacleArea(const S_NavigationObstacleCylinder& obstacle) = 0;
    virtual dtNavMesh* GetNavMesh(NavigationAgentTypeID agentTypeId) = 0;
    virtual C_TileCacheUpdateManager* GetTileCacheUpdateManager(NavigationAgentTypeID agentTypeId) = 0;
    virtual I_PathFinder* GetPathFinder() = 0;              // [7]  C_Navigation: 0x181A77FC0  this+0x150
    virtual wh::shared::C_Listeners<I_ReplanMovesNotify, 1>* GetReplanMovesListeners() = 0;
    virtual C_PathSpeedLimiter* GetPathSpeedLimiter() = 0;
    virtual C_MovementTaskManager* GetMovementTaskManager() = 0;
    virtual C_NavMeshObstacleManager* GetNavMeshObstacleManager() = 0;
    virtual C_ReplanMoveAreaRegistry* GetReplanMoveAreaRegistry() = 0;         // [12] 0x181A77FA0  this+0x178
    virtual void RebuildNavigationSystem() = 0;
    virtual void BuildSurfaceTypeLookup() = 0;
    virtual void StartNavigation() = 0;
    virtual void StopNavigation() = 0;
    virtual void ClearLevelNavigation() = 0;
    virtual void Update(float frameTime, bool skipPathfinderUpdate, std::uint32_t pathfinderUpdateFlags) = 0;
    virtual void ResetAllNPCMovementRequests() = 0;
    virtual std::size_t GetAgentTypeCount() const = 0;
    virtual NavigationAgentTypeID GetAgentTypeID(std::size_t index) const = 0;
    virtual const char* GetAgentTypeName(NavigationAgentTypeID agentTypeId) const = 0;
    virtual bool IsAgentTypeValid(NavigationAgentTypeID agentTypeId) const = 0;
    // Writes *id = m_defaultNavMeshId (+0x88) and returns id.  C_Navigation: 0x180813390.
    virtual uint32_t* GetDefaultNavMeshId(uint32_t* id) const = 0;            // [24]
    virtual float GetAgentHeight(NavigationAgentTypeID agentTypeId) const = 0;
    virtual float GetAgentHorizontalVoxelSize(NavigationAgentTypeID agentTypeId) const = 0;
    virtual float GetAgentRadius(NavigationAgentTypeID agentTypeId) const = 0;
    virtual float GetAgentClimbableHeight(NavigationAgentTypeID agentTypeId) const = 0;
    virtual void GetAgentContext(NavigationAgentTypeID agentTypeId, S_NavigationAgentContext& context) const = 0;
    virtual std::uint32_t GetAgentTileGridSize(NavigationAgentTypeID agentTypeId) const = 0;
    virtual void SetMNMOverrideEnabled(bool enabled) = 0;
    virtual void SetMovementSpeedOverrideEnabled(bool enabled) = 0;
    virtual S_NavMeshQueryContext* GetNavMeshQueryContext(NavigationAgentTypeID agentTypeId) = 0;
    virtual S_PathFindingResult* CreatePathResult() = 0;    // [34] 0x1834100E8  alloc 0x18, zeroed
    virtual void DestroyPathResult(S_PathFindingResult* result) = 0;          // [35] 0x183410238
    virtual C_OffMeshLinksManager* GetOffMeshLinksManager(NavigationAgentTypeID agentTypeId) = 0;
    virtual S_EngineNavigationAgent* GetEngineNavigationAgent(NavigationAgentTypeID agentTypeId) = 0;
    virtual S_NavMeshSource GetNavMeshSource(NavigationAgentTypeID agentTypeId, const Vec3& position) const = 0;
    virtual I_RayCastHelper* GetSharedRayCastHelper() = 0;
    virtual I_RayCastHelper* CreateRayCastHelper() = 0;
    virtual void DestroyRayCastHelper(I_RayCastHelper* helper) = 0;
};
static_assert(sizeof(I_Navigation) == 0x08, "I_Navigation is a vptr-only interface");

}  // namespace wh::xgenaimodule::navigation
