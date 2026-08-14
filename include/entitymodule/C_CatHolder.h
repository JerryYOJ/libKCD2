#pragma once
#include <cstddef>
#include <cstdint>
#include "S_CatHolderPathState.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"

namespace wh::entitymodule {

#pragma pack(push, 4)
class C_CatHolder
    : public Offsets::CGameObjectExtensionHelper<
          C_CatHolder,
          Offsets::IGameObjectExtension,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CatHolder;

    ~C_CatHolder() override;                                       // [0] 0x1828F0BE4
    void ProcessEvent(SEntityEvent& event) override;               // [1] 0x180B1CC44
    bool _vf2() override;                                          // [2] 0x180838AE0
    int GetEventPriority(int eventId) override;                    // [3] 0x181A74280
    void _vf4() override;                                          // [4] nullsub
    Offsets::IEntity* GetEntity() override;                        // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;          // [6] 0x1828F5E2C
    bool Init(Offsets::IGameObject* gameObject) override;          // [7] 0x181467DB8
    void PostInit(Offsets::IGameObject* gameObject) override;      // [8] 0x180B1CE68
    void InitClient(int channelId) override;                       // [9] nullsub
    void PostInitClient(int channelId) override;                   // [10] nullsub
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11] 0x1828F9258
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub
    bool GetEntityPoolSignature(TSerialize signature) override;   // [13] 0x1828F5000
    void Release() override;                                      // [14] 0x180B1CC20
    void FullSerialize(TSerialize serializer) override;           // [15] 0x1828F4210
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override;                         // [16] 0x180838AE0
    bool _vf17() override;                                         // [17] 0x180838AE0
    NetworkAspectType GetNetSerializeAspects() override;           // [18] 0x181A72600
    void PostSerialize() override;                                 // [19] nullsub
    void SerializeSpawnInfo(TSerialize serializer) override;      // [20] nullsub
    ISerializableInfoPtr GetSpawnInfo() override;                  // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] 0x180B1C4A4
    void HandleEvent(const SGameObjectEvent& event) override;      // [23] nullsub
    void SetChannelId(std::uint16_t id) override;                  // [24] nullsub
    void SetAuthority(bool authoritative) override;                // [25] nullsub
    void PostUpdate(float frameTime) override;                     // [27] nullsub
    void PostRemoteSpawn() override;                               // [28] nullsub

    S_CatHolderPathState m_pathState;                              // +0x40
    CryStringT<char> m_unknownE8;                                  // +0xE8, role OPEN
    std::uint8_t m_stateF0;                                       // +0xF0, role OPEN
    std::uint8_t _padF1[3];                                       // +0xF1
    std::uint64_t m_handleF4;                                     // +0xF4, role OPEN
    std::uint8_t m_stateFC;                                       // +0xFC, role OPEN
    std::uint8_t _padFD[3];                                       // +0xFD
    std::int32_t m_index100;                                      // +0x100, init -1
    std::uint32_t m_state104;                                     // +0x104, role OPEN
    std::uint8_t m_mode108;                                       // +0x108, init 2
    std::uint8_t m_state109;                                      // +0x109, role OPEN
    std::uint8_t _pad10A[2];                                      // +0x10A
    std::uint32_t m_state10C;                                     // +0x10C, role OPEN
    bool m_callbackRegistered0;                                   // +0x110
    bool m_callbackRegistered1;                                   // +0x111
    std::uint8_t _pad112[6];                                      // +0x112
};
#pragma pack(pop)

static_assert(sizeof(C_CatHolder) == 0x118,
              "C_CatHolder must be 0x118");
static_assert(offsetof(C_CatHolder, m_pathState) == 0x40,
              "CatHolder path state must be at 0x40");
static_assert(offsetof(C_CatHolder, m_unknownE8) == 0xE8,
              "CatHolder string must be at 0xE8");
static_assert(offsetof(C_CatHolder, m_handleF4) == 0xF4,
              "CatHolder packed handle must be at 0xF4");
static_assert(offsetof(C_CatHolder, m_callbackRegistered0) == 0x110,
              "CatHolder callback flags must start at 0x110");

}  // namespace wh::entitymodule
