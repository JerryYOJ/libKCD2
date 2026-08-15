#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "E_InteractiveObjectState.h"
#include "S_InteractiveObjectInteraction.h"
#include "../CryEngine/CryCommon/physinterface.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IEntity.h"
#include "../Offsets/vtables/IGameObjectExtension.h"

namespace wh::entitymodule {

class C_InteractiveObjectEx
    : public Offsets::CGameObjectExtensionHelper<
          C_InteractiveObjectEx,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_InteractiveObjectEx;

    ~C_InteractiveObjectEx() override;                                  // [0] 0x1829FD6E8
    void ProcessEvent(SEntityEvent& event) override;                    // [1] 0x182A01574
    bool _vf2() override;                                                // [2] false stub
    int GetEventPriority(int eventId) override;                         // [3] 0x181A74280
    void _vf4() override;                                                // [4] nullsub
    Offsets::IEntity* GetEntity() override;                             // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;               // [6] 0x1829FFBA0
    bool Init(Offsets::IGameObject* gameObject) override;               // [7] 0x182A00070
    void PostInit(Offsets::IGameObject* gameObject) override;           // [8] nullsub
    void InitClient(int channelId) override;                            // [9] nullsub
    void PostInitClient(int channelId) override;                       // [10] nullsub
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override;    // [11] 0x182A01978
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub
    bool GetEntityPoolSignature(TSerialize signature) override;        // [13] true stub
    void Release() override;                                            // [14] 0x1803A5684
    void FullSerialize(TSerialize serializer) override;                // [15] 0x1829FF6C0
    bool NetSerialize(TSerialize serializer, EEntityAspects aspect,
                      std::uint8_t profile, int flags) override;        // [16] 0x182A004C0
    bool _vf17() override;                                               // [17] false stub
    NetworkAspectType GetNetSerializeAspects() override;               // [18] 0x181A72600
    void PostSerialize() override;                                      // [19] 0x182A0104C
    void SerializeSpawnInfo(TSerialize serializer) override;           // [20] nullsub
    ISerializableInfoPtr GetSpawnInfo() override;                       // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] nullsub
    void HandleEvent(const SGameObjectEvent& event) override;           // [23] nullsub
    void SetChannelId(std::uint16_t id) override;                       // [24] nullsub
    void SetAuthority(bool authoritative) override;                     // [25] nullsub
    const void* GetRMIBase() const override;                            // [26] 0x181A88890
    void PostUpdate(float frameTime) override;                          // [27] nullsub
    void PostRemoteSpawn() override;                                    // [28] nullsub

    virtual void Use(EntityId userId);                                  // [29] 0x182A03340
    virtual void StopUse();                                             // [30] 0x182A02E48
    virtual void AbortUse();                                            // [31] 0x1829FD810

    std::vector<S_InteractiveObjectInteraction> m_interactions; // +0x40
    S_InteractiveObjectInteraction m_activeInteraction;        // +0x58, source name reconstructed
    E_InteractiveObjectState m_state;                           // +0x88, serialized as "m_state"
    pe_type m_physicalizationType;                              // +0x8C, source name reconstructed
    std::uint32_t m_interactId;                                 // +0x90, network key "interactId"
    std::uint32_t m_interactionNameId;                          // +0x94, invalid is 0xFFFFFFFF
    std::int32_t m_selectedInteractionId;                       // +0x98, invalid is -1
    std::uint32_t m_modelSlot;                                  // +0x9C, exact source role OPEN
    std::uint8_t m_animType;                                    // +0xA0, network key "animType"
    bool m_removeDecalsOnUse;                                   // +0xA1
    bool m_startInteractionOnExplosion;                         // +0xA2
    std::uint8_t _padA3[5];                                     // +0xA3
};
static_assert(sizeof(C_InteractiveObjectEx) == 0xA8,
              "C_InteractiveObjectEx must be 0xA8");
static_assert(offsetof(C_InteractiveObjectEx, m_interactions) == 0x40,
              "interactive-object interactions must be at 0x40");
static_assert(offsetof(C_InteractiveObjectEx, m_activeInteraction) == 0x58,
              "active interaction must be at 0x58");
static_assert(offsetof(C_InteractiveObjectEx, m_state) == 0x88,
              "interactive-object state must be at 0x88");
static_assert(offsetof(C_InteractiveObjectEx, m_interactId) == 0x90,
              "interactive-object interact id must be at 0x90");
static_assert(offsetof(C_InteractiveObjectEx, m_animType) == 0xA0,
              "interactive-object animation type must be at 0xA0");

}  // namespace wh::entitymodule
