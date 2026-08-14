#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/SRainParams.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"

struct ITexture;

namespace wh::environmentmodule {

class C_Rain
    : public Offsets::CGameObjectExtensionHelper<
          C_Rain,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Rain;

    ~C_Rain() override;                                               // [0] 0x182ADAA28
    void ProcessEvent(SEntityEvent& event) override;                  // [1] 0x182ADB780
    bool _vf2() override;                                             // [2] 0x180838AE0
    int GetEventPriority(int eventId) override;                       // [3] 0x181A74280
    void _vf4() override;                                             // [4] nullsub_1
    Offsets::IEntity* GetEntity() override;                           // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;             // [6] 0x182ADB590
    bool Init(Offsets::IGameObject* gameObject) override;             // [7] 0x182ADB5AC
    void PostInit(Offsets::IGameObject* gameObject) override;         // [8] 0x182ADB5E0
    void InitClient(int channelId) override;                          // [9] nullsub_1
    void PostInitClient(int channelId) override;                      // [10] nullsub_1
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override;  // [11] 0x182A01978
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub_1
    bool GetEntityPoolSignature(TSerialize signature) override;      // [13] 0x18041A6A0
    void Release() override;                                          // [14] 0x1803A5684
    void FullSerialize(TSerialize serializer) override;              // [15] 0x182ADAD20
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override;                            // [16] 0x18041A6A0
    bool _vf17() override;                                            // [17] 0x180838AE0, role OPEN
    NetworkAspectType GetNetSerializeAspects() override;              // [18] 0x181A72600
    void PostSerialize() override;                                    // [19] nullsub_1
    void SerializeSpawnInfo(TSerialize serializer) override;         // [20] nullsub_1
    ISerializableInfoPtr GetSpawnInfo() override;                     // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] 0x182ADBB10
    void HandleEvent(const SGameObjectEvent& event) override;         // [23] nullsub_1
    void SetChannelId(std::uint16_t id) override;                     // [24] nullsub_1
    void SetAuthority(bool authoritative) override;                   // [25] nullsub_1
    void PostUpdate(float frameTime) override;                        // [27] nullsub_1
    void PostRemoteSpawn() override;                                  // [28] nullsub_1

    SRainParams m_rainParams;              // +0x40
    bool m_enabled;                        // +0x160, serialized as bEnabled
    std::uint8_t _pad161[7];               // +0x161
    std::vector<ITexture*> m_rainTextures; // +0x168, owning references
};

static_assert(sizeof(C_Rain) == 0x180,
              "C_Rain must be 0x180");
static_assert(offsetof(C_Rain, m_rainParams) == 0x40,
              "rain parameters must be at 0x40");
static_assert(offsetof(C_Rain, m_enabled) == 0x160,
              "rain enabled flag must be at 0x160");
static_assert(offsetof(C_Rain, m_rainTextures) == 0x168,
              "rain texture vector must be at 0x168");

}  // namespace wh::environmentmodule
