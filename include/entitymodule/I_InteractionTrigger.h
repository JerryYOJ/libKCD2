#pragma once
#include <cstddef>
#include <cstdint>
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "../framework/C_Signal.h"
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class I_InteractionTrigger : public Offsets::IGameObjectExtension {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_InteractionTrigger;

    ~I_InteractionTrigger() override;                                // [0] 0x1829FD784
    void ProcessEvent(SEntityEvent& event) override;                 // [1] nullsub_1
    bool _vf2() override;                                            // [2] 0x180838AE0
    int GetEventPriority(int eventId) override;                      // [3] 0x181A74280
    void _vf4() override;                                            // [4] nullsub_1
    Offsets::IEntity* GetEntity() override;                          // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;            // [6] 0x18260F714
    bool Init(Offsets::IGameObject* gameObject) override;            // [7] 0x180707074
    void PostInit(Offsets::IGameObject* gameObject) override;        // [8] nullsub_1
    void InitClient(int channelId) override;                         // [9] nullsub_1
    void PostInitClient(int channelId) override;                     // [10] nullsub_1
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11] 0x1827D22E8
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub_1
    bool GetEntityPoolSignature(TSerialize signature) override;     // [13] 0x1829FF96C
    void Release() override;                                        // [14] 0x1803A5684
    void FullSerialize(TSerialize serializer) override;             // [15] nullsub_1
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override;                           // [16] 0x180838AE0
    bool _vf17() override;                                           // [17] 0x180838AE0, role OPEN
    NetworkAspectType GetNetSerializeAspects() override;             // [18] 0x181A72600
    void PostSerialize() override;                                   // [19] nullsub_1
    void SerializeSpawnInfo(TSerialize serializer) override;        // [20] nullsub_1
    ISerializableInfoPtr GetSpawnInfo() override;                    // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] nullsub_1
    void HandleEvent(const SGameObjectEvent& event) override;        // [23] nullsub_1
    void SetChannelId(std::uint16_t id) override;                    // [24] nullsub_1
    void SetAuthority(bool authoritative) override;                  // [25] nullsub_1
    void PostUpdate(float frameTime) override;                       // [27] nullsub_1
    void PostRemoteSpawn() override;                                 // [28] nullsub_1

    virtual bool IsPressEnabled() const;                             // [29], source constness OPEN
    virtual bool IsHoldEnabled() const;                              // [30], source constness OPEN
    virtual void SetPressEnabled(bool enabled);                      // [31], name reconstructed
    virtual void SetHoldEnabled(bool enabled);                       // [32], name reconstructed
    virtual void SetPressed();                                      // [33]
    virtual void SetHeld();                                         // [34]

    RTTR_ENABLE() // [35..37]

    wh::shared::C_Signal<I_InteractionTrigger*> m_onPressed; // +0x40, name reconstructed
    wh::shared::C_Signal<I_InteractionTrigger*> m_onHeld;    // +0x50, name reconstructed
    std::int32_t m_priority;                                // +0x60, name reconstructed
    bool m_pressEnabled;                                    // +0x64, name reconstructed
    bool m_holdEnabled;                                     // +0x65, name reconstructed
};
static_assert(sizeof(I_InteractionTrigger) == 0x68,
              "I_InteractionTrigger must be 0x68");
static_assert(offsetof(I_InteractionTrigger, m_onPressed) == 0x40,
              "press signal must be at 0x40");
static_assert(offsetof(I_InteractionTrigger, m_onHeld) == 0x50,
              "hold signal must be at 0x50");
static_assert(offsetof(I_InteractionTrigger, m_priority) == 0x60,
              "interaction priority must be at 0x60");
static_assert(offsetof(I_InteractionTrigger, m_pressEnabled) == 0x64,
              "press-enabled flag must be at 0x64");
static_assert(offsetof(I_InteractionTrigger, m_holdEnabled) == 0x65,
              "hold-enabled flag must be at 0x65");

}  // namespace wh::entitymodule
