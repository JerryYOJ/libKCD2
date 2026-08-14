#pragma once
#include <cstddef>
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "C_LinkableObjectHolder.h"

namespace wh::xgenaimodule {

class C_LinkableObjectExtension
    : public Offsets::CGameObjectExtensionHelper<
          C_LinkableObjectExtension,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_LinkableObjectExtension;
    ~C_LinkableObjectExtension() override;                              // [0] 0x18096D3F0
    void ProcessEvent(SEntityEvent& event) override;                    // [1] nullsub_1
    bool _vf2() override;                                               // [2] 0x180838AE0
    int GetEventPriority(int eventId) override;                         // [3] 0x181A74280, returns 7
    void _vf4() override;                                               // [4] nullsub_1
    Offsets::IEntity* GetEntity() override;                             // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;               // [6] nullsub_1
    bool Init(Offsets::IGameObject* gameObject) override;               // [7] 0x18096E264
    void PostInit(Offsets::IGameObject* gameObject) override;           // [8] nullsub_1
    void InitClient(int channelId) override;                            // [9] nullsub_1
    void PostInitClient(int channelId) override;                        // [10] nullsub_1
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override;     // [11] 0x1832F36CC
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub_1
    bool GetEntityPoolSignature(TSerialize signature) override;         // [13] 0x1832F3410
    void Release() override;                                            // [14] 0x18096D5FC
    void FullSerialize(TSerialize serializer) override;                 // [15] nullsub_1
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override;                              // [16] 0x180838AE0
    bool _vf17() override;                                              // [17] 0x180838AE0, role OPEN
    NetworkAspectType GetNetSerializeAspects() override;                // [18] 0x181A72600
    void PostSerialize() override;                                      // [19] nullsub_1
    void SerializeSpawnInfo(TSerialize serializer) override;           // [20] nullsub_1
    ISerializableInfoPtr GetSpawnInfo() override;                       // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] nullsub_1
    void HandleEvent(const SGameObjectEvent& event) override;           // [23] nullsub_1
    void SetChannelId(std::uint16_t id) override;                       // [24] nullsub_1
    void SetAuthority(bool authoritative) override;                     // [25] nullsub_1
    void PostUpdate(float frameTime) override;                          // [27] nullsub_1
    void PostRemoteSpawn() override;                                    // [28] nullsub_1

    C_LinkableObjectHolder m_holder; // +0x40
};
static_assert(sizeof(C_LinkableObjectExtension) == 0x58,
              "C_LinkableObjectExtension must be 0x58");
static_assert(offsetof(C_LinkableObjectExtension, m_holder) == 0x40,
              "linkable-object holder must be at 0x40");

}  // namespace wh::xgenaimodule
