#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "S_RuntimePrefabAutoPhaseEntry.h"

namespace wh::entitymodule {

class C_RuntimePrefabAutoPhase
    : public Offsets::CGameObjectExtensionHelper<
          C_RuntimePrefabAutoPhase,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RuntimePrefabAutoPhase;

    ~C_RuntimePrefabAutoPhase() override;                              // [0] 0x181543ACC
    void ProcessEvent(SEntityEvent& event) override;                   // [1] 0x1815439C8
    bool _vf2() override;                                               // [2] false stub
    int GetEventPriority(int eventId) override;                        // [3] 0x181A74280
    void _vf4() override;                                               // [4] nullsub_1
    Offsets::IEntity* GetEntity() override;                            // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;              // [6] 0x18260F714
    bool Init(Offsets::IGameObject* gameObject) override;              // [7] 0x180DBDBF4
    void PostInit(Offsets::IGameObject* gameObject) override;          // [8] nullsub_1
    void InitClient(int channelId) override;                           // [9] nullsub_1
    void PostInitClient(int channelId) override;                       // [10] nullsub_1
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override;   // [11] 0x1827D22E8
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub_1
    bool GetEntityPoolSignature(TSerialize signature) override;       // [13] 0x182ABB6E0
    void Release() override;                                           // [14] 0x181543A90
    void FullSerialize(TSerialize serializer) override;               // [15] nullsub_1
    bool NetSerialize(TSerialize serializer, EEntityAspects aspect,
                      std::uint8_t profile, int flags) override;       // [16] false stub
    bool _vf17() override;                                              // [17] false stub
    NetworkAspectType GetNetSerializeAspects() override;              // [18] 0x181A72600
    void PostSerialize() override;                                     // [19] nullsub_1
    void SerializeSpawnInfo(TSerialize serializer) override;          // [20] nullsub_1
    ISerializableInfoPtr GetSpawnInfo() override;                      // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] nullsub_1
    void HandleEvent(const SGameObjectEvent& event) override;          // [23] nullsub_1
    void SetChannelId(std::uint16_t id) override;                      // [24] nullsub_1
    void SetAuthority(bool authoritative) override;                    // [25] nullsub_1
    const void* GetRMIBase() const override;                           // [26] 0x181AB4CA0
    void PostUpdate(float frameTime) override;                         // [27] nullsub_1
    void PostRemoteSpawn() override;                                   // [28] nullsub_1

    std::vector<S_RuntimePrefabAutoPhaseEntry> m_phaseSchedule; // +0x40
    std::int64_t m_worldTimeDelayStdDevMs;                      // +0x58
    bool m_changeWhenVisible;                                  // +0x60
};
static_assert(sizeof(C_RuntimePrefabAutoPhase) == 0x68,
              "C_RuntimePrefabAutoPhase must be 0x68");
static_assert(offsetof(C_RuntimePrefabAutoPhase, m_phaseSchedule) == 0x40,
              "phase schedule must be at 0x40");
static_assert(offsetof(C_RuntimePrefabAutoPhase, m_worldTimeDelayStdDevMs) == 0x58,
              "world-time delay standard deviation must be at 0x58");
static_assert(offsetof(C_RuntimePrefabAutoPhase, m_changeWhenVisible) == 0x60,
              "visibility-change flag must be at 0x60");

}  // namespace wh::entitymodule
