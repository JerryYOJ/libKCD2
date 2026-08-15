#pragma once
#include <cstddef>
#include <cstdint>
#include "I_TagPoint.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"

namespace wh::entitymodule {

class C_TagPointWithScript
    : public I_TagPoint,
      public Offsets::CGameObjectExtensionHelper<
          C_TagPointWithScript,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_TagPointWithScript;

    Offsets::IEntity* GetTagPointEntity() override; // primary [0] 0x181A8B5A0
    RTTR_ENABLE(I_TagPoint) // primary [1..3]

    ~C_TagPointWithScript() override;                                // secondary [0] 0x18213E510
    void ProcessEvent(SEntityEvent& event) override;                 // secondary [1] nullsub
    bool _vf2() override;                                             // secondary [2] false stub
    int GetEventPriority(int eventId) override;                      // secondary [3] 0x181A74280
    void _vf4() override;                                             // secondary [4] nullsub
    Offsets::IEntity* GetEntity() override;                          // secondary [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;            // secondary [6] 0x182AA7548
    bool Init(Offsets::IGameObject* gameObject) override;            // secondary [7] 0x181938F24
    void PostInit(Offsets::IGameObject* gameObject) override;        // secondary [8] nullsub
    void InitClient(int channelId) override;                         // secondary [9] nullsub
    void PostInitClient(int channelId) override;                    // secondary [10] nullsub
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // secondary [11] 0x1827D22E8
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // secondary [12] nullsub
    bool GetEntityPoolSignature(TSerialize signature) override;     // secondary [13] 0x182AA72A0
    void Release() override;                                         // secondary [14] 0x181835B34
    void FullSerialize(TSerialize serializer) override;             // secondary [15] nullsub
    bool NetSerialize(TSerialize serializer, EEntityAspects aspect,
                      std::uint8_t profile, int flags) override;     // secondary [16] false stub
    bool _vf17() override;                                            // secondary [17] false stub
    NetworkAspectType GetNetSerializeAspects() override;            // secondary [18] 0x181A72600
    void PostSerialize() override;                                   // secondary [19] nullsub
    void SerializeSpawnInfo(TSerialize serializer) override;        // secondary [20] nullsub
    ISerializableInfoPtr GetSpawnInfo() override;                    // secondary [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // secondary [22] nullsub
    void HandleEvent(const SGameObjectEvent& event) override;        // secondary [23] nullsub
    void SetChannelId(std::uint16_t id) override;                    // secondary [24] nullsub
    void SetAuthority(bool authoritative) override;                  // secondary [25] nullsub
    const void* GetRMIBase() const override;                         // secondary [26] 0x181AB4CF0
    void PostUpdate(float frameTime) override;                       // secondary [27] nullsub
    void PostRemoteSpawn() override;                                 // secondary [28] nullsub
};
static_assert(sizeof(C_TagPointWithScript) == 0x48,
              "C_TagPointWithScript must be 0x48");

}  // namespace wh::entitymodule
