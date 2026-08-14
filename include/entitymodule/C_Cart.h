#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include "I_Cart.h"
#include "S_CartReservation.h"
#include "../CryEngine/CryCommon/CryThread_windows.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../framework/C_Signal.h"

namespace wh::entitymodule {

class C_Cart
    : public Offsets::CGameObjectExtensionHelper<C_Cart, I_Cart, 64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Cart;

    ~C_Cart() override;                                             // [0] 0x1812969A4
    void ProcessEvent(SEntityEvent& event) override;                // [1] 0x180F8F3E8
    bool _vf2() override;                                           // [2] 0x18041A6A0
    int GetEventPriority(int eventId) override;                     // [3] 0x1819B465C
    void _vf4() override;                                           // [4] nullsub
    Offsets::IEntity* GetEntity() override;                         // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;           // [6] 0x1828D92DC
    bool Init(Offsets::IGameObject* gameObject) override;           // [7] 0x181297030
    void PostInit(Offsets::IGameObject* gameObject) override;       // [8] 0x180DF0D2C
    void InitClient(int channelId) override;                        // [9] nullsub
    void PostInitClient(int channelId) override;                    // [10] nullsub
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11] 0x1827D22E8
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub
    bool GetEntityPoolSignature(TSerialize signature) override;    // [13] 0x1828D86F8
    void Release() override;                                       // [14] 0x181296974
    void FullSerialize(TSerialize serializer) override;            // [15] 0x1828D7FC8
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override;                          // [16] 0x180838AE0
    bool _vf17() override;                                          // [17] 0x18041A6A0
    NetworkAspectType GetNetSerializeAspects() override;            // [18] 0x181A72600
    void PostSerialize() override;                                  // [19] nullsub
    void SerializeSpawnInfo(TSerialize serializer) override;       // [20] nullsub
    ISerializableInfoPtr GetSpawnInfo() override;                   // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] nullsub
    void HandleEvent(const SGameObjectEvent& event) override;       // [23] nullsub
    void SetChannelId(std::uint16_t id) override;                   // [24] nullsub
    void SetAuthority(bool authoritative) override;                 // [25] nullsub
    void PostUpdate(float frameTime) override;                      // [27] nullsub
    void PostRemoteSpawn() override;                                // [28] nullsub

    std::uint8_t GetStateCode_29() const override;                  // [29] 0x1828D9E38
    QuatT GetTransform_30() const override;                          // [30] 0x1828D9B7C
    bool Operation_31(std::uint64_t argument1,
                      std::uint64_t argument2,
                      bool apply) override;                         // [31] 0x1828DC924
    bool QueryCandidate_32(std::uint64_t candidate) const override; // [32] 0x1828DB180
    void Operation_33() override;                                   // [33] 0x1828DD934
    void SetStateFlag_34(bool enabled) override;                    // [34] 0x1828DCA14
    void SetFiveValue_35(std::uint8_t index,
                         std::int32_t value) override;              // [35] 0x181A83F00
    bool QueryLocalTransform_36(std::uint8_t selector,
                                QuatT& result) override;             // [36] 0x1828D9D18
    bool QueryWorldTransform_37(std::uint8_t selector,
                                QuatT& result) override;             // [37] 0x1828D9D94
    EntityId GetTwoEntityId_38(std::uint8_t index) const override;  // [38] 0x181A83E00
    EntityId GetSevenEntityId_39(std::uint8_t index) const override; // [39] 0x181A83E10
    bool AcquireTwoSlot_40(Offsets::IGameObjectExtension* object,
                           std::uint8_t index) override;             // [40] 0x1828D49C8
    bool AcquireSevenSlot_41(Offsets::IGameObjectExtension* object,
                             std::uint8_t index) override;           // [41] 0x1828D4A74
    void ReleaseTwoSlot_42(std::uint8_t index) override;             // [42] 0x1828DF004
    void ReleaseSevenSlot_43(std::uint8_t index) override;           // [43] 0x1828DF074
    bool CanAcquireSevenSlot_44(std::uint8_t index,
                                Offsets::IGameObjectExtension* object) const override; // [44] 0x1828D4B40
    bool CanAcquireTwoSlot_45(std::uint8_t index) const override;    // [45] 0x1828D4B80
    bool IsSevenSlot2Enabled_46() const override;                    // [46] 0x181A83EA0
    bool IsStateZero_47() const override;                            // [47] 0x1828DA8AC
    void AdjustGateCount_48(bool acquire) override;                 // [48] 0x1828D74F8
    void* GetSupportA8_49() override;                                // [49] 0x181A74C20
    void* GetEmbeddedSupport_50() override;                          // [50] 0x181A834C0
    void AddCallback_51(const S_CartDelegateToken& token) override; // [51] 0x1828D5E98
    void RemoveCallback_52(const S_CartDelegateToken& token) override; // [52] 0x1828D72C0
    bool IsSevenStateOne_53(std::uint8_t index) const override;     // [53] 0x1828DA800

    wh::shared::C_Signal<> m_callbacks40;                           // +0x40, payload OPEN
    wh::shared::C_Signal<> m_callbacks50;                           // +0x50, payload OPEN
    wh::shared::C_Signal<std::uint8_t, bool> m_onReservationChanged; // +0x60
    std::uint32_t m_state70;                                       // +0x70, role OPEN
    std::uint8_t m_opaque74[4];                                    // +0x74
    CryRWLock m_reservationLock;                                   // +0x78
    std::uint64_t m_state80;                                       // +0x80, role OPEN
    std::uint16_t m_state88;                                       // +0x88, role OPEN
    bool m_operationEnabled;                                       // +0x8A
    std::uint8_t m_opaque8B[5];                                    // +0x8B
    void* m_pActiveAssociation;                                    // +0x90, borrowed
    void* m_pTransformProvider;                                    // +0x98, owned
    void* m_pState;                                                // +0xA0, owned trivial allocation
    void* m_pSupportA8;                                            // +0xA8, owned
    void* m_pSupportB0;                                            // +0xB0, owned
    std::array<std::int32_t, 5> m_fiveValues;                      // +0xB8
    std::array<std::int32_t, 7> m_sevenState;                      // +0xCC
    std::array<S_CartReservation, 7> m_sevenReservations;          // +0xE8
    std::array<S_CartReservation, 2> m_twoReservations;            // +0x120
    std::array<bool, 7> m_sevenSlotEnabled;                        // +0x130
    std::uint8_t m_opaque137;                                      // +0x137
    std::shared_ptr<void> m_embeddedSupport;                       // +0x138, shared-ownership shape; exact type OPEN
    void* m_pCache148;                                             // +0x148, borrowed/cache
    bool m_flag150;                                                // +0x150, role OPEN
    std::uint8_t m_opaque151[0x0B];                                // +0x151
    std::uint32_t m_gateCount;                                     // +0x15C
    std::uint32_t m_state160;                                      // +0x160, role OPEN
    std::uint32_t m_state164;                                      // +0x164, role OPEN
    std::uint32_t m_state168;                                      // +0x168, role OPEN
    std::uint8_t m_opaque16C[4];                                   // +0x16C
};

static_assert(sizeof(CryRWLock) == 0x08,
              "CryRWLock must be 0x08");
static_assert(sizeof(C_Cart) == 0x170,
              "C_Cart must be 0x170");
static_assert(offsetof(C_Cart, m_callbacks40) == 0x40,
              "first Cart callback signal must be at 0x40");
static_assert(offsetof(C_Cart, m_reservationLock) == 0x78,
              "Cart reservation lock must be at 0x78");
static_assert(offsetof(C_Cart, m_fiveValues) == 0xB8,
              "Cart five-value array must be at 0xB8");
static_assert(offsetof(C_Cart, m_sevenReservations) == 0xE8,
              "Cart seven reservations must be at 0xE8");
static_assert(offsetof(C_Cart, m_twoReservations) == 0x120,
              "Cart two reservations must be at 0x120");
static_assert(offsetof(C_Cart, m_embeddedSupport) == 0x138,
              "Cart embedded support must be at 0x138");
static_assert(offsetof(C_Cart, m_gateCount) == 0x15C,
              "Cart gate count must be at 0x15C");

}  // namespace wh::entitymodule
