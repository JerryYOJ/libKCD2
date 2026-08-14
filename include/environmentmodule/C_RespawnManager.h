#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_set>
#include <vector>
#include "I_RespawnManager.h"
#include "C_PickableAreaInstanceGrid.h"
#include "S_PickableAreaInstance.h"
#include "S_PickableAreaRespawnRecord.h"
#include "S_PickableAreaRespawnRecordHash.h"
#include "S_PickableAreaRespawnRecordEqual.h"
#include "../Offsets/vtables/IMergeMeshStreamListener.h"
#include "../Offsets/vtables/IConsole.h"

// -----------------------------------------------
// wh::environmentmodule::C_RespawnManager -- pickable-area render-instance manager
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x1C8.
// -----------------------------------------------
// Bases: I_RespawnManager @+0x00, IMergeMeshStreamListener @+0x08. Inline ctor
// in C_EnvironmentModule::Init sub_180E3C398; dtor sub_182ADCCDC. It owns the
// selected plant record, the shared PickableArea proxy EntityId, consumed-instance
// wake-up records, and the streamed merged-mesh indexing state.

class CMergedMeshRenderNode;

namespace wh::environmentmodule {

class C_RespawnManager : public I_RespawnManager,
                         public Offsets::IMergeMeshStreamListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RespawnManager;

    ~C_RespawnManager() override; // primary [0]
    Offsets::IEntity* FindPickableArea(const Vec3& rayStart,
                                       const Vec3& rayEnd) override; // [1] sub_1809F2B14
    int32_t ConsumeSelectedPickableArea() override;                  // [2] sub_182ADDFA4
    bool CollectPickableAreaCounts(
        wh::xgenaimodule::I_Area& area,
        const std::vector<uint8_t>& pickableAreaIds,
        std::unordered_map<uint8_t, uint32_t>& counts) override;     // [3] sub_182ADE080 [SYNTHETIC NAME]

    void OnMergedMeshStreamedIn(CMergedMeshRenderNode* pNode) override;  // secondary [0] sub_18043AAA4
    void OnMergedMeshStreamedOut(CMergedMeshRenderNode* pNode) override; // secondary [1] sub_182ADEA68

    Vec3   m_lastRaycastPosition;               // +0x10
    uint8_t _pad1C[4];                          // +0x1C
    ICVar* m_cvarRespawnDistance;               // +0x20
    ICVar* m_cvarRespawnDebug;                  // +0x28
    ICVar* m_cvarRespawnDebugIntervalSec;       // +0x30
    ICVar* m_cvarRespawnPickDistance;           // +0x38
    ICVar* m_cvarGridInsertDistanceSquared;     // +0x40
    ICVar* m_cvarTypicalHerbHeight;             // +0x48
    ICVar* m_cvarRespawnHerbBboxScale;          // +0x50
    ICVar* m_cvarRaycastUpdateDelta;            // +0x58
    S_PickableAreaInstance m_selectedInstance;  // +0x60
    uint32_t m_proxyEntityId;                   // +0x90  persistent "Herb_InteractorEntity"
    uint32_t m_activeProxyEntityId;             // +0x94  zero without a current selection
    C_PickableAreaInstanceGrid* m_pInstanceGrid; // +0x98  owned spatial index
    std::unordered_set<S_PickableAreaRespawnRecord,
                       S_PickableAreaRespawnRecordHash,
                       S_PickableAreaRespawnRecordEqual> m_respawnRecords; // +0xA0
    std::vector<S_PickableAreaRespawnRecord> m_loadedRespawnRecords; // +0xE0  transient post-load queue
    std::unordered_set<CMergedMeshRenderNode*> m_registeredMergedMeshNodes; // +0xF8
    std::unordered_set<CMergedMeshRenderNode*> m_pendingMergedMeshNodes;    // +0x138
    std::unordered_set<CMergedMeshRenderNode*> m_indexedMergedMeshNodes;    // +0x178
    bool    m_cachedActorStateMaskMatch;        // +0x1B8 [SYNTHETIC NAME]
    uint8_t _pad1B9[3];                        // +0x1B9
    int32_t m_cachedAIAnimationState;           // +0x1BC float-to-int actor-state gate [SYNTHETIC NAME]
    bool    m_callbacksRegistered;              // +0x1C0
    uint8_t _pad1C1[7];                        // +0x1C1
};
static_assert(sizeof(C_RespawnManager) == 0x1C8,
              "C_RespawnManager must match the 0x1C8 allocation");
static_assert(offsetof(C_RespawnManager, m_selectedInstance) == 0x60,
              "selected instance must begin at +0x60");
static_assert(offsetof(C_RespawnManager, m_proxyEntityId) == 0x90,
              "proxy EntityId must be at +0x90");
static_assert(offsetof(C_RespawnManager, m_activeProxyEntityId) == 0x94,
              "active proxy EntityId must be at +0x94");
static_assert(offsetof(C_RespawnManager, m_pInstanceGrid) == 0x98,
              "instance-grid pointer must be at +0x98");
static_assert(offsetof(C_RespawnManager, m_respawnRecords) == 0xA0,
              "respawn-record set must be at +0xA0");
static_assert(offsetof(C_RespawnManager, m_loadedRespawnRecords) == 0xE0,
              "loaded respawn-record queue must be at +0xE0");
static_assert(offsetof(C_RespawnManager, m_registeredMergedMeshNodes) == 0xF8,
              "registered merged-mesh set must be at +0xF8");
static_assert(offsetof(C_RespawnManager, m_pendingMergedMeshNodes) == 0x138,
              "pending merged-mesh set must be at +0x138");
static_assert(offsetof(C_RespawnManager, m_indexedMergedMeshNodes) == 0x178,
              "indexed merged-mesh set must be at +0x178");
static_assert(offsetof(C_RespawnManager, m_cachedAIAnimationState) == 0x1BC,
              "cached AI-animation state must be at +0x1BC");
static_assert(offsetof(C_RespawnManager, m_callbacksRegistered) == 0x1C0,
              "callback-registration flag must be at +0x1C0");

}  // namespace wh::environmentmodule
