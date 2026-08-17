#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/physinterface.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IActor.h"
#include "../Offsets/vtables/IEntitySystem.h"
#include "../Offsets/vtables/IViewSystem.h"
#include "../Offsets/vtables/IWorldQuery.h"

namespace Offsets { class IPhysicalWorld; }

class CWorldQuery
    : public Offsets::CGameObjectExtensionHelper<
          CWorldQuery,
          Offsets::IWorldQuery,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CWorldQuery;

    CWorldQuery();
    ~CWorldQuery() override; // [0]
    void ProcessEvent(SEntityEvent& event) override; // [1]
    bool _vf2() override; // [2]
    int GetEventPriority(int eventId) override; // [3]
    void _vf4() override; // [4]
    Offsets::IEntity* GetEntity() override; // [5]
    void GetMemoryUsage(ICrySizer* sizer) const override; // [6]
    bool Init(Offsets::IGameObject* gameObject) override; // [7]
    void PostInit(Offsets::IGameObject* gameObject) override; // [8]
    void InitClient(int channelId) override; // [9]
    void PostInitClient(int channelId) override; // [10]
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11]
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12]
    bool GetEntityPoolSignature(TSerialize signature) override; // [13]
    void Release() override; // [14]
    void FullSerialize(TSerialize serializer) override; // [15]
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override; // [16]
    bool _vf17() override; // [17]
    NetworkAspectType GetNetSerializeAspects() override; // [18]
    void PostSerialize() override; // [19]
    void SerializeSpawnInfo(TSerialize serializer) override; // [20]
    ISerializableInfoPtr GetSpawnInfo() override; // [21]
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22]
    void HandleEvent(const SGameObjectEvent& event) override; // [23]
    void SetChannelId(std::uint16_t id) override; // [24]
    void SetAuthority(bool authoritative) override; // [25]
    const void* GetRMIBase() const override; // [26]
    void PostUpdate(float frameTime) override; // [27]
    void PostRemoteSpawn() override; // [28]
    Offsets::IEntity* GetEntityInFrontOf() override; // [29]
    const EntityId* ProximityQuery(int& count) override; // [30]
    const Vec3& GetPos() const override; // [31]
    const Vec3& GetDir() const override; // [32]
    EntityId GetLookAtEntityId(bool ignoreGlass = false) override; // [33]
    const ray_hit* GetLookAtPoint(float maxDistance = 0.0f,
                                  bool ignoreGlass = false) override; // [34]
    const ray_hit* GetBehindPoint(float maxDistance = 0.0f) override; // [35]
    const EntityId* GetEntitiesAround(int& count) override; // [36]
    ::IPhysicalEntity* const* GetPhysicalEntitiesAround(int& count) override; // [37]
    ::IPhysicalEntity* GetPhysicalEntityInFrontOf() override; // [38]

    std::uint32_t m_cacheMask; // +0x040
    std::int32_t m_lastQueryFrameId; // +0x044
    float m_proximityRadius; // +0x048
    Vec3 m_position; // +0x04C
    Vec3 m_direction; // +0x058
    std::byte _pad064[0x04]; // +0x064
    Offsets::IActor* m_pActor; // +0x068, borrowed
    Offsets::IPhysicalWorld* m_pPhysicalWorld; // +0x070, borrowed
    Offsets::IEntitySystem* m_pEntitySystem; // +0x078, borrowed
    Offsets::IViewSystem* m_pViewSystem; // +0x080, borrowed
    bool m_hasLookAtHit; // +0x088
    std::byte _pad089[0x07]; // +0x089
    ray_hit m_primaryLookAtHit; // +0x090
    ray_hit m_secondaryLookAtHit; // +0x0E0, exact role OPEN
    bool m_hasBehindHit; // +0x130
    std::byte _pad131[0x07]; // +0x131
    ray_hit m_behindHit; // +0x138
    EntityId m_lookAtEntityId; // +0x188
    std::byte _pad18C[0x04]; // +0x18C
    std::vector<EntityId> m_proximityResults; // +0x190
    std::vector<EntityId> m_entityInFrontCandidates; // +0x1A8
    std::vector<EntityId> m_entitiesAround; // +0x1C0
    std::vector<::IPhysicalEntity*> m_physicalEntitiesAround; // +0x1D8
    int m_physicalEntityInFrontId; // +0x1F0
    std::byte _pad1F4[0x04]; // +0x1F4
};
static_assert(sizeof(CWorldQuery) == 0x1F8,
              "CWorldQuery must be 0x1F8");
static_assert(offsetof(CWorldQuery, m_cacheMask) == 0x40,
              "world-query cache mask must be at 0x40");
static_assert(offsetof(CWorldQuery, m_pActor) == 0x68,
              "world-query actor must be at 0x68");
static_assert(offsetof(CWorldQuery, m_primaryLookAtHit) == 0x90,
              "world-query primary look-at hit must be at 0x90");
static_assert(offsetof(CWorldQuery, m_behindHit) == 0x138,
              "world-query behind hit must be at 0x138");
static_assert(offsetof(CWorldQuery, m_proximityResults) == 0x190,
              "world-query proximity results must be at 0x190");
static_assert(offsetof(CWorldQuery, m_physicalEntitiesAround) == 0x1D8,
              "world-query physical results must be at 0x1D8");
static_assert(offsetof(CWorldQuery, m_physicalEntityInFrontId) == 0x1F0,
              "world-query physical-front ID must be at 0x1F0");
