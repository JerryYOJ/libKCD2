#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "../rttr/rttr_enable.h"
#include "C_BattlementSlot.h"

namespace wh::playermodule {

class C_Battlement
    : public Offsets::CGameObjectExtensionHelper<
          C_Battlement,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Battlement;

    ~C_Battlement() override;                                        // [0] 0x18127F3C8
    void ProcessEvent(SEntityEvent& event) override;                 // [1] 0x1815CE8BC
    bool _vf2() override;                                            // [2] 0x18041A6A0
    int GetEventPriority(int eventId) override;                      // [3] 0x181A74280
    void _vf4() override;                                            // [4] nullsub_1
    Offsets::IEntity* GetEntity() override;                          // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;            // [6] 0x182E58C68
    bool Init(Offsets::IGameObject* gameObject) override;            // [7] 0x18127F388
    void PostInit(Offsets::IGameObject* gameObject) override;        // [8] 0x180AB3C70
    void InitClient(int channelId) override;                         // [9] nullsub_1
    void PostInitClient(int channelId) override;                     // [10] nullsub_1
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11] 0x180838AE0
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub_1
    bool GetEntityPoolSignature(TSerialize signature) override;     // [13] 0x180838AE0
    void Release() override;                                        // [14] 0x18127F2CC
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

    RTTR_ENABLE() // [29..31]

    Vec3 m_worldPoint0;                              // +0x40, from vectorPoint0
    Vec3 m_worldPoint1;                              // +0x4C, from vectorPoint1
    float m_slotWidth;                               // +0x58
    float m_merlonWidth;                             // +0x5C
    std::uint8_t m_wallType;                         // +0x60: wall=0, palisade=1; native enum identity OPEN
    std::vector<C_BattlementSlot*> m_slots;          // +0x68, owns elements
};
static_assert(sizeof(C_Battlement) == 0x80, "C_Battlement must be 0x80");
static_assert(offsetof(C_Battlement, m_worldPoint0) == 0x40,
              "first world point must be at 0x40");
static_assert(offsetof(C_Battlement, m_wallType) == 0x60,
              "wall-type byte must be at 0x60");
static_assert(offsetof(C_Battlement, m_slots) == 0x68,
              "owned slot vector must be at 0x68");

}  // namespace wh::playermodule
