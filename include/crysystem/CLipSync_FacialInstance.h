#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "CLipSyncProvider_FacialInstance.h"

class CLipSync_FacialInstance
    : public Offsets::CGameObjectExtensionHelper<
          CLipSync_FacialInstance,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CLipSync_FacialInstance;

    CLipSync_FacialInstance();
    ~CLipSync_FacialInstance() override; // [0]
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

    std::shared_ptr<CLipSyncProvider_FacialInstance> m_lipSyncProvider; // +0x40
};
static_assert(sizeof(CLipSync_FacialInstance) == 0x50,
              "CLipSync_FacialInstance must be 0x50");
static_assert(offsetof(CLipSync_FacialInstance, m_lipSyncProvider) == 0x40,
              "facial lip-sync provider owner must be at 0x40");
