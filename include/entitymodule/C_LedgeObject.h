#pragma once
#include <cstddef>
#include <cstdint>
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class C_LedgeObject
    : public Offsets::CGameObjectExtensionHelper<
          C_LedgeObject,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_LedgeObject;

    ~C_LedgeObject() override;                                         // [0] 0x1812D586C
    void ProcessEvent(SEntityEvent& event) override;                   // [1] 0x180EC511C
    bool _vf2() override;                                               // [2] false stub
    int GetEventPriority(int eventId) override;                        // [3] 0x181A74280
    void _vf4() override;                                               // [4] nullsub
    Offsets::IEntity* GetEntity() override;                            // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;              // [6] nullsub
    bool Init(Offsets::IGameObject* gameObject) override;              // [7] 0x1816EB5A0
    void PostInit(Offsets::IGameObject* gameObject) override;          // [8] 0x180EC515C
    void InitClient(int channelId) override;                           // [9] nullsub
    void PostInitClient(int channelId) override;                      // [10] nullsub
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override;   // [11] 0x182A8AC14
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub
    bool GetEntityPoolSignature(TSerialize signature) override;       // [13] true stub
    void Release() override;                                           // [14] 0x1803A5684
    void FullSerialize(TSerialize serializer) override;               // [15] nullsub
    bool NetSerialize(TSerialize serializer, EEntityAspects aspect,
                      std::uint8_t profile, int flags) override;       // [16] false stub
    bool _vf17() override;                                              // [17] false stub
    NetworkAspectType GetNetSerializeAspects() override;              // [18] 0x181A72600
    void PostSerialize() override;                                     // [19] nullsub
    void SerializeSpawnInfo(TSerialize serializer) override;          // [20] nullsub
    ISerializableInfoPtr GetSpawnInfo() override;                      // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] nullsub
    void HandleEvent(const SGameObjectEvent& event) override;          // [23] 0x182A89FB0
    void SetChannelId(std::uint16_t id) override;                      // [24] nullsub
    void SetAuthority(bool authoritative) override;                    // [25] nullsub
    const void* GetRMIBase() const override;                           // [26] 0x181A8AD40
    void PostUpdate(float frameTime) override;                         // [27] nullsub
    void PostRemoteSpawn() override;                                   // [28] nullsub

    virtual bool IsStaticLedge() const;                                // [29], source name reconstructed
    RTTR_ENABLE() // [30..32]

    bool m_ledgeFlipped;          // +0x40, property "bLedgeFlipped"
    std::uint8_t _pad41[3];       // +0x41
    std::uint32_t m_unknown44;    // +0x44, constructor-only role OPEN
};
static_assert(sizeof(C_LedgeObject) == 0x48,
              "C_LedgeObject must be 0x48");
static_assert(offsetof(C_LedgeObject, m_ledgeFlipped) == 0x40,
              "ledge-flipped flag must be at 0x40");
static_assert(offsetof(C_LedgeObject, m_unknown44) == 0x44,
              "open ledge dword must be at 0x44");

}  // namespace wh::entitymodule
