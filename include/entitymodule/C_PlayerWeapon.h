#pragma once
#include <cstdint>
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "../framework/I_ModuleMessageListener.h"

namespace wh::entitymodule {

class C_PlayerWeapon
    : public Offsets::CGameObjectExtensionHelper<
          C_PlayerWeapon,
          Offsets::IGameObjectExtension,
          64>,
      public framework::I_ModuleMessageListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PlayerWeapon;

    ~C_PlayerWeapon() override;                                        // primary [0] 0x1839D8504; secondary thunk 0x18213E4F8
    void ProcessEvent(SEntityEvent& event) override;                   // primary [1] 0x1829AA198
    bool _vf2() override;                                               // primary [2] false stub
    int GetEventPriority(int eventId) override;                        // primary [3] 0x181A74280
    void _vf4() override;                                               // primary [4] nullsub_1
    Offsets::IEntity* GetEntity() override;                            // primary [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;              // primary [6] 0x1828C4AD8
    bool Init(Offsets::IGameObject* gameObject) override;              // primary [7] 0x1829A88FC
    void PostInit(Offsets::IGameObject* gameObject) override;          // primary [8] nullsub_1
    void InitClient(int channelId) override;                           // primary [9] nullsub_1
    void PostInitClient(int channelId) override;                       // primary [10] nullsub_1
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override;   // primary [11] 0x1827D22E8
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // primary [12] nullsub_1
    bool GetEntityPoolSignature(TSerialize signature) override;       // primary [13] 0x1829A87C8
    void Release() override;                                           // primary [14] 0x1829AA414
    void FullSerialize(TSerialize serializer) override;               // primary [15] nullsub_1
    bool NetSerialize(TSerialize serializer, EEntityAspects aspect,
                      std::uint8_t profile, int flags) override;       // primary [16] false stub
    bool _vf17() override;                                              // primary [17] false stub
    NetworkAspectType GetNetSerializeAspects() override;              // primary [18] 0x181A72600
    void PostSerialize() override;                                     // primary [19] nullsub_1
    void SerializeSpawnInfo(TSerialize serializer) override;          // primary [20] nullsub_1
    ISerializableInfoPtr GetSpawnInfo() override;                      // primary [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // primary [22] nullsub_1
    void HandleEvent(const SGameObjectEvent& event) override;          // primary [23] nullsub_1
    void SetChannelId(std::uint16_t id) override;                      // primary [24] nullsub_1
    void SetAuthority(bool authoritative) override;                    // primary [25] nullsub_1
    const void* GetRMIBase() const override;                           // primary [26] 0x181AB4C70
    void PostUpdate(float frameTime) override;                         // primary [27] nullsub_1
    void PostRemoteSpawn() override;                                   // primary [28] nullsub_1

    void OnModuleMessage(void* message) override;                      // secondary [1] 0x1829AA1B0
};
static_assert(sizeof(C_PlayerWeapon) == 0x48,
              "C_PlayerWeapon must be 0x48");

}  // namespace wh::entitymodule
