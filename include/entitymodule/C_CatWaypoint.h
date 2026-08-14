#pragma once
#include <cstddef>
#include <cstdint>
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"

namespace wh::entitymodule {

class C_CatWaypoint
    : public Offsets::CGameObjectExtensionHelper<
          C_CatWaypoint,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CatWaypoint;

    ~C_CatWaypoint() override;                                     // [0] 0x18116D748
    void ProcessEvent(SEntityEvent& event) override;               // [1] nullsub
    bool _vf2() override;                                          // [2] 0x180838AE0
    int GetEventPriority(int eventId) override;                    // [3] 0x181A74280
    void _vf4() override;                                          // [4] nullsub
    Offsets::IEntity* GetEntity() override;                        // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;          // [6] 0x1824AA0DC
    bool Init(Offsets::IGameObject* gameObject) override;          // [7] 0x1816EB5A0
    void PostInit(Offsets::IGameObject* gameObject) override;      // [8] nullsub
    void InitClient(int channelId) override;                       // [9] nullsub
    void PostInitClient(int channelId) override;                   // [10] nullsub
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11] 0x1827D22E8
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub
    bool GetEntityPoolSignature(TSerialize signature) override;   // [13] 0x1828F5030
    void Release() override;                                      // [14] nullsub
    void FullSerialize(TSerialize serializer) override;           // [15] nullsub
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override;                         // [16] 0x180838AE0
    bool _vf17() override;                                         // [17] 0x180838AE0
    NetworkAspectType GetNetSerializeAspects() override;           // [18] 0x181A72600
    void PostSerialize() override;                                 // [19] nullsub
    void SerializeSpawnInfo(TSerialize serializer) override;      // [20] nullsub
    ISerializableInfoPtr GetSpawnInfo() override;                  // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] nullsub
    void HandleEvent(const SGameObjectEvent& event) override;      // [23] nullsub
    void SetChannelId(std::uint16_t id) override;                  // [24] nullsub
    void SetAuthority(bool authoritative) override;                // [25] nullsub
    void PostUpdate(float frameTime) override;                     // [27] nullsub
    void PostRemoteSpawn() override;                               // [28] nullsub
};

static_assert(sizeof(C_CatWaypoint) == 0x40,
              "C_CatWaypoint must be 0x40");

}  // namespace wh::entitymodule
