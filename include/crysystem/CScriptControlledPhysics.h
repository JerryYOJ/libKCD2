#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "CScriptableBase.h"

class CScriptControlledPhysics
    : public Offsets::CGameObjectExtensionHelper<
          CScriptControlledPhysics,
          Offsets::IGameObjectExtension,
          64>
    , public CScriptableBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CScriptControlledPhysics;

    CScriptControlledPhysics();
    ~CScriptControlledPhysics() override; // [0]
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

    bool m_moving;                       // +0xA0
    Vec3 m_moveTarget;                   // +0xA4
    Vec3 m_moveVelocity;                 // +0xB0, source spelling OPEN
    float m_speed;                       // +0xBC
    float m_maxSpeed;                    // +0xC0
    float m_acceleration;                // +0xC4
    float m_stopTime;                    // +0xC8
    bool m_rotating;                     // +0xCC
    Quat m_rotationTarget;               // +0xD0
    float m_rotationSpeed;               // +0xE0
    float m_rotationMaxSpeed;            // +0xE4
    float m_rotationAcceleration;        // +0xE8
    float m_rotationStopTime;            // +0xEC
};
static_assert(sizeof(CScriptControlledPhysics) == 0xF0,
              "CScriptControlledPhysics must be 0xF0");
static_assert(offsetof(CScriptControlledPhysics, m_moving) == 0xA0,
              "script-controlled motion state must begin at 0xA0");
static_assert(offsetof(CScriptControlledPhysics, m_moveVelocity) == 0xB0,
              "script-controlled move velocity must be at 0xB0");
static_assert(offsetof(CScriptControlledPhysics, m_rotationTarget) == 0xD0,
              "script-controlled rotation target must be at 0xD0");
