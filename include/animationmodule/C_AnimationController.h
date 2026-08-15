#pragma once
#include <cstddef>
#include <cstdint>
#include "C_LODAnimationController.h"
#include "I_AnimationController.h"
#include "../CryEngine/CryCommon/CryThread_windows.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"

struct IAnimatedCharacter;

namespace wh::animationmodule {

class C_AnimationController
    : public Offsets::CGameObjectExtensionHelper<
          C_AnimationController,
          Offsets::IGameObjectExtension,
          64>,
      public I_AnimationController {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_AnimationController;

    ~C_AnimationController() override;                                  // primary [0] 0x180498C20
    void ProcessEvent(SEntityEvent& event) override;                    // primary [1] 0x18068540C
    bool _vf2() override;                                                // primary [2] false stub
    int GetEventPriority(int eventId) override;                         // primary [3] 0x181A74280
    void _vf4() override;                                                // primary [4] nullsub; also secondary [4]
    Offsets::IEntity* GetEntity() override;                             // primary [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;               // primary [6] nullsub
    bool Init(Offsets::IGameObject* gameObject) override;               // primary [7] 0x180498E34
    void PostInit(Offsets::IGameObject* gameObject) override;           // primary [8] nullsub
    void InitClient(int channelId) override;                            // primary [9] nullsub
    void PostInitClient(int channelId) override;                        // primary [10] nullsub
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override;    // primary [11] 0x1827D22E8
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // primary [12] nullsub
    bool GetEntityPoolSignature(TSerialize signature) override;        // primary [13] 0x1827D2144
    void Release() override;                                            // primary [14] 0x1803A5684
    void FullSerialize(TSerialize serializer) override;                // primary [15] nullsub
    bool NetSerialize(TSerialize serializer, EEntityAspects aspect,
                      std::uint8_t profile, int flags) override;        // primary [16] false stub
    bool _vf17() override;                                               // primary [17] false stub
    NetworkAspectType GetNetSerializeAspects() override;                // primary [18] 0x181A72600
    void PostSerialize() override;                                      // primary [19] nullsub
    void SerializeSpawnInfo(TSerialize serializer) override;           // primary [20] nullsub
    ISerializableInfoPtr GetSpawnInfo() override;                       // primary [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // primary [22] nullsub
    void HandleEvent(const SGameObjectEvent& event) override;           // primary [23] nullsub
    void SetChannelId(std::uint16_t id) override;                       // primary [24] nullsub
    void SetAuthority(bool authoritative) override;                     // primary [25] nullsub
    const void* GetRMIBase() const override;                            // primary [26] 0x181A7F950
    void PostUpdate(float frameTime) override;                          // primary [27] nullsub
    void PostRemoteSpawn() override;                                    // primary [28] nullsub

    bool QueueAction(IAction& action, float time,
                     bool restartInstalled) override;                   // secondary [1] 0x1827D225C
    I_LODAnimationController* GetLODAnimationController() override;     // secondary [2] 0x181A73320
    I_AnimationControllerTestable* GetTestable() override;              // secondary [3] 0x181A749E0
    void SetSuspended(std::int32_t mode) override;                      // secondary [5] 0x181E5A720

    bool m_initialized;                         // +0x48
    std::uint8_t _pad49[7];                     // +0x49
    IAnimatedCharacter* m_pAnimatedCharacter;   // +0x50, borrowed extension
    CryRWLock m_updateLock;                     // +0x58
    void* m_unknown60;                          // +0x60, role/pointee OPEN
    C_LODAnimationController m_lodController;   // +0x68
    std::uint32_t m_unknown170;                 // +0x170, reset before update; role OPEN
    bool m_updateRegistered;                    // +0x174, manager-list registration flag
    bool m_parallelUpdateRegistered;            // +0x175, manager-list registration flag
    std::uint8_t m_suspendCount;                // +0x176
    std::uint8_t _pad177;                       // +0x177
};
static_assert(sizeof(C_AnimationController) == 0x178,
              "C_AnimationController must be 0x178");
static_assert(offsetof(C_AnimationController, m_initialized) == 0x48,
              "animation-controller initialized flag must be at 0x48");
static_assert(offsetof(C_AnimationController, m_lodController) == 0x68,
              "LOD animation controller must be at 0x68");
static_assert(offsetof(C_AnimationController, m_unknown170) == 0x170,
              "animation-controller update state must be at 0x170");

}  // namespace wh::animationmodule
