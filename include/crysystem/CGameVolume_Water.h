#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "SGameVolumeWaterPart.h"

class CGameVolume_Water
    : public Offsets::CGameObjectExtensionHelper<
          CGameVolume_Water,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CGameVolume_Water;

    CGameVolume_Water();
    ~CGameVolume_Water() override; // [0]
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

    std::vector<SGameVolumeWaterPart> m_parts; // +0x40
    Matrix34 m_worldTM;                        // +0x58
    Matrix34 m_worldTMCopy;                    // +0x88, exact role OPEN
    Vec3 m_lastWakePosition;                   // +0xB8
    float m_volumeDepth;                       // +0xC4
    float m_streamSpeed;                       // +0xC8
    bool m_awakeAreaWhenMoving;                // +0xCC
    bool m_isRiver;                            // +0xCD
};
static_assert(sizeof(CGameVolume_Water) == 0xD0,
              "CGameVolume_Water must be 0xD0");
static_assert(offsetof(CGameVolume_Water, m_parts) == 0x40,
              "water-volume parts must be at 0x40");
static_assert(offsetof(CGameVolume_Water, m_worldTM) == 0x58,
              "water-volume world transform must be at 0x58");
static_assert(offsetof(CGameVolume_Water, m_lastWakePosition) == 0xB8,
              "water-volume wake position must be at 0xB8");
static_assert(offsetof(CGameVolume_Water, m_awakeAreaWhenMoving) == 0xCC,
              "water-volume wake flag must be at 0xCC");
