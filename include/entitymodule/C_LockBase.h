#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "../framework/C_Signal.h"
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class C_LockBase
    : public Offsets::CGameObjectExtensionHelper<
          C_LockBase,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_LockBase;

    ~C_LockBase() override;                                          // [0] 0x1809656AC
    void ProcessEvent(SEntityEvent& event) override;                 // [1] nullsub_1
    bool _vf2() override;                                            // [2] 0x180838AE0
    int GetEventPriority(int eventId) override;                      // [3] 0x181A74280
    void _vf4() override;                                            // [4] nullsub_1
    Offsets::IEntity* GetEntity() override;                          // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;            // [6] nullsub_1
    bool Init(Offsets::IGameObject* gameObject) override;            // [7] 0x1807063A4
    void PostInit(Offsets::IGameObject* gameObject) override;        // [8] nullsub_1
    void InitClient(int channelId) override;                         // [9] nullsub_1
    void PostInitClient(int channelId) override;                     // [10] nullsub_1
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub_1
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

    virtual const char* GetExtensionName() const = 0;                // [29], exact name OPEN
    virtual bool CanUnlockWithItemClass(const CryGUID& itemClassId) const; // [30], name/cv OPEN

    RTTR_ENABLE() // [31..33]

    wh::shared::C_Signal<> m_signal40; // +0x40, template payload/role OPEN
    wh::shared::C_Signal<> m_signal50; // +0x50, template payload/role OPEN
    wh::shared::C_Signal<> m_signal60; // +0x60, template payload/role OPEN
};
static_assert(sizeof(C_LockBase) == 0x70, "C_LockBase must be 0x70");
static_assert(offsetof(C_LockBase, m_signal40) == 0x40,
              "first lock signal must be at 0x40");
static_assert(offsetof(C_LockBase, m_signal60) == 0x60,
              "third lock signal must be at 0x60");

}  // namespace wh::entitymodule
