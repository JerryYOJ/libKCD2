#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "E_StoneThrowingOrientation.h"
#include "E_StoneThrowingThrowType.h"
#include "S_StoneThrowingCacheEntry.h"
#include "S_StoneThrowingNodePair.h"
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "../framework/C_Signal.h"
#include "../framework/CryDeferrable.h"

namespace wh::playermodule {

class C_StoneThrowingPile
    : public Offsets::CGameObjectExtensionHelper<
          C_StoneThrowingPile,
          Offsets::IGameObjectExtension,
          64>,
      public UnsafeOp::CryDeferrable<1> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_StoneThrowingPile;

    // Native nested enum identity is emitted; enumerator names come from exact class/link roles.
    enum class E_EntityType : std::int32_t {
        Node = 0,
        GeomEntity = 1,
        PickPoint = 2,
    };

    ~C_StoneThrowingPile() override;                                // [0] 0x1839D8558
    void ProcessEvent(SEntityEvent& event) override;               // [1] 0x180D7D8FC
    bool _vf2() override;                                          // [2] true stub
    int GetEventPriority(int eventId) override;                    // [3] 0x181A74280
    void _vf4() override;                                          // [4] nullsub
    Offsets::IEntity* GetEntity() override;                        // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;          // [6] 0x182EAAA7C
    bool Init(Offsets::IGameObject* gameObject) override;          // [7] 0x1816EB5A0
    void PostInit(Offsets::IGameObject* gameObject) override;      // [8] nullsub
    void InitClient(int channelId) override;                       // [9] nullsub
    void PostInitClient(int channelId) override;                   // [10] nullsub
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11] false stub
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub
    bool GetEntityPoolSignature(TSerialize signature) override;   // [13] false stub
    void Release() override;                                      // [14] 0x1803A5684
    void FullSerialize(TSerialize serializer) override;           // [15] 0x182EAA27C
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override;                         // [16] false stub
    bool _vf17() override;                                         // [17] false stub
    NetworkAspectType GetNetSerializeAspects() override;           // [18] 0x181A72600
    void PostSerialize() override;                                 // [19] 0x182EAF3C0
    void SerializeSpawnInfo(TSerialize serializer) override;      // [20] nullsub
    ISerializableInfoPtr GetSpawnInfo() override;                  // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] 0x182EB3D1C
    void HandleEvent(const SGameObjectEvent& event) override;      // [23] nullsub
    void SetChannelId(std::uint16_t id) override;                  // [24] nullsub
    void SetAuthority(bool authoritative) override;                // [25] nullsub
    void PostUpdate(float frameTime) override;                     // [27] nullsub
    void PostRemoteSpawn() override;                               // [28] nullsub

    wh::shared::C_Signal<> m_signal40;                             // +0x40, payload/role OPEN
    float m_unknown50;                                             // +0x50, init 3.0f; role OPEN
    float m_unknown54;                                             // +0x54, init 0.3f; role OPEN
    float m_rollingEffectLifetime;                                 // +0x58, init 0.5f
    std::uint32_t _pad5C;                                         // +0x5C
    std::vector<std::shared_ptr<S_StoneThrowingCacheEntry>> m_entries; // +0x60
    std::shared_ptr<S_StoneThrowingCacheEntry> m_preparedStone;    // +0x78
    EntityId m_referenceEntityId;                                 // +0x88, role OPEN
    std::uint32_t _pad8C;                                         // +0x8C
    std::vector<S_StoneThrowingNodePair> m_nodePairs;              // +0x90
    E_StoneThrowingOrientation m_orientation;                      // +0xA8
    E_StoneThrowingThrowType m_throwType;                          // +0xA9
    std::uint8_t _padAA[2];                                       // +0xAA
    Matrix34 m_worldTransform;                                     // +0xAC
    std::int32_t m_serializedStoneCount;                           // +0xDC, "stones"; init -1
};

static_assert(sizeof(C_StoneThrowingPile::E_EntityType) == 0x04,
              "StoneThrowingPile entity type must be four bytes");
static_assert(sizeof(C_StoneThrowingPile) == 0xE0,
              "C_StoneThrowingPile must be 0xE0");
static_assert(offsetof(C_StoneThrowingPile, m_signal40) == 0x40,
              "stone pile signal must be at 0x40");
static_assert(offsetof(C_StoneThrowingPile, m_entries) == 0x60,
              "stone cache-entry vector must be at 0x60");
static_assert(offsetof(C_StoneThrowingPile, m_preparedStone) == 0x78,
              "prepared stone must be at 0x78");
static_assert(offsetof(C_StoneThrowingPile, m_referenceEntityId) == 0x88,
              "stone pile reference entity must be at 0x88");
static_assert(offsetof(C_StoneThrowingPile, m_nodePairs) == 0x90,
              "stone node pairs must be at 0x90");
static_assert(offsetof(C_StoneThrowingPile, m_orientation) == 0xA8,
              "stone orientation must be at 0xA8");
static_assert(offsetof(C_StoneThrowingPile, m_worldTransform) == 0xAC,
              "stone pile transform must be at 0xAC");
static_assert(offsetof(C_StoneThrowingPile, m_serializedStoneCount) == 0xDC,
              "serialized stone count must be at 0xDC");

}  // namespace wh::playermodule
