#pragma once
#include <boost/container/vector.hpp>
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/BaseTypes.h"
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/primitives.h"
#include "../CryEngine/CryCommon/physinterface.h"
#include "../CryEngine/CryAction/IHitListener.h"
#include "../CryEngine/CryCommon/TimeValue.h"
#include "../EntityEffects/CEffectsController.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "../Offsets/vtables/IGameObjectProfileManager.h"
#include "../framework/C_Signal.h"
#include "../framework/WUID.h"
#include "C_ItemWrapper.h"
#include "ProjectileFlags.h"
#include "SProjectileDesc.h"

struct SAmmoParams;
struct SExplodeDesc;

namespace wh::entitymodule {

// KCD2 WHGame.dll 1.5.6: primary 0x18471D020, IHitListener +0x40,
// IGameObjectProfileManager +0x48; allocation witness 0x182944050.
class CProjectile
    : public Offsets::CGameObjectExtensionHelper<
          CProjectile,
          Offsets::IGameObjectExtension,
          64>
    , public IHitListener
    , public Offsets::IGameObjectProfileManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CProjectile;

    ~CProjectile() override;                                           // [0] 0x182A9FCDC
    void ProcessEvent(SEntityEvent& event) override;                   // [1] 0x182AAAFFC
    bool _vf2() override;                                              // [2] 0x180838AE0
    int GetEventPriority(int eventId) override;                        // [3] 0x181A74280
    void _vf4() override;                                              // [4] nullsub_1
    Offsets::IEntity* GetEntity() override;                            // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;              // [6] 0x182AA7484
    bool Init(Offsets::IGameObject* gameObject) override;              // [7] 0x182AA7B20
    void PostInit(Offsets::IGameObject* gameObject) override;          // [8] 0x182AAA3CC
    void InitClient(int channelId) override;                           // [9] nullsub_1
    void PostInitClient(int channelId) override;                       // [10] nullsub_1
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override;   // [11] 0x182AAB6C4
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub_1
    bool GetEntityPoolSignature(TSerialize signature) override;       // [13] 0x18041A6A0
    void Release() override;                                           // [14] 0x1803A5684
    void FullSerialize(TSerialize serializer) override;               // [15] 0x182AA2EE4
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override;                             // [16] 0x182AA8D64
    bool _vf17() override;                                             // [17] 0x180838AE0
    NetworkAspectType GetNetSerializeAspects() override;               // [18] 0x181A8B5B0
    void PostSerialize() override;                                     // [19] nullsub_1
    void SerializeSpawnInfo(TSerialize serializer) override;          // [20] 0x182AAC6E4
    ISerializableInfoPtr GetSpawnInfo() override;                      // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] 0x182AAE300
    void HandleEvent(const SGameObjectEvent& event) override;          // [23] 0x182AA7918
    void SetChannelId(std::uint16_t id) override;                      // [24] nullsub_1
    void SetAuthority(bool authoritative) override;                    // [25] nullsub_1
    void PostUpdate(float frameTime) override;                         // [27] nullsub_1
    void PostRemoteSpawn() override;                                   // [28] 0x182AAA444

    virtual std::size_t GetMemorySize() const;                         // [29] 0x181A85B00
    virtual void ReInitFromPool();                                     // [30] 0x182AAB48C
    virtual void _vf31();                                              // [31] 0x182AAB840, emits entity events 0x110/0x111
    virtual void SetParams(const SProjectileDesc& desc);               // [32] 0x182AAD190
    virtual void SetDestinationPosition(const Vec3& position);         // [33] nullsub_1
    virtual void SetDestinationEntity(EntityId targetId);              // [34] nullsub_1
    virtual void Launch(const Vec3& position,
                        const Vec3& direction,
                        const Vec3& velocity,
                        float speedScale);                             // [35] 0x182AA85A8
    virtual bool IsAlive() const;                                      // [36] 0x18041A6A0
    virtual void Deflected(const Vec3& direction);                     // [37] nullsub_1
    virtual bool Detonate();                                           // [38] 0x18041A6A0
    virtual bool CanDetonate();                                        // [39] 0x18041A6A0
    virtual void Explode(const SExplodeDesc& desc);                    // [40] nullsub_1
    virtual void SetDamageCap(float cap);                              // [41] nullsub_1
    virtual void UpdateLinkedDamage(EntityId hitActorId,
                                    float totalAccumulatedDamage);      // [42] nullsub_1
    virtual void CreateBulletTrail(const Vec3& hitPosition);           // [43] nullsub_1
    virtual EntityId GetStuckToEntityId() const;                       // [44] 0x18066CD10
    virtual float ComputeBallisticRange(float height,
                                        float angle,
                                        float speed,
                                        float gravity) const;           // [45] 0x182AA13A0
    virtual bool ShouldCollisionsDamageTarget() const;                 // [46] 0x180838AE0
    virtual bool HandleCollision(const EventPhysCollision& collision); // [47] 0x182AA78A0
    virtual void SetUpParticleParams(Offsets::IEntity* ownerEntity,
                                     std::uint8_t pierceabilityModifier); // [48] 0x182AAD3F8
    virtual void _vf49();                                              // [49] 0x182AAE694, swept-AABB proximity scan
    virtual void _vf50(Offsets::IEntity* entity);                      // [50] 0x182AA913C, proximity callback

    void OnHit(const HitInfo& hit) override;                           // hit [1] 0x182AA9AAC
    void OnExplosion(const ExplosionInfo& explosion) override;        // hit [2] 0x182AA9A6C
    void OnServerExplosion(const ExplosionInfo& explosion) override;  // hit [3] 0x182AA9C20

    bool SetAspectProfile(EEntityAspects aspect,
                          std::uint8_t profile) override;              // profile [1] 0x182AAC810
    std::uint8_t GetDefaultProfile(EEntityAspects aspect) override;   // profile [2] 0x182AA3394
    std::uint8_t GetAspectProfile(
        EEntityAspects aspect) const override;                        // profile [3] 0x182AA3394
    void ConnectProfileChanged(
        const Offsets::S_ProfileChangedDelegate& delegate) override;  // profile [4] 0x18295D160
    void DisconnectProfileChanged(
        const Offsets::S_ProfileChangedDelegate& delegate) override;  // profile [5] 0x18295D7E4

    wh::shared::C_Signal<
        Offsets::IEntity*,
        EEntityAspects,
        std::uint8_t,
        std::uint8_t> m_profileSignal;              // +0x050
    CTimeValue m_spawnTime;                         // +0x060
    const SAmmoParams* m_pAmmoParams;               // +0x068, borrowed
    IPhysicalEntity* m_pPhysicalEntity;             // +0x070, borrowed
    EntityEffects::CEffectsController m_effects;    // +0x078
    ProjectileFlags m_projectileFlags;              // +0x0A0
    Vec3 m_last;                                    // +0x0A4
    Vec3 m_initialPosition;                         // +0x0B0
    Vec3 m_initialDirection;                        // +0x0BC
    Vec3 m_initialVelocity;                         // +0x0C8
    float m_minDamageForKnockDown;                  // +0x0D4
    float m_minDamageForKnockDownLeg;               // +0x0D8
    float m_totalLifetime;                          // +0x0DC
    float m_scaledEffectValue;                      // +0x0E0
    float m_unknownE4;                              // +0x0E4, role OPEN
    float m_mpDestructionDelay;                     // +0x0E8
    EntityEffects::TAttachedEffectId m_trailEffectId; // +0x0EC
    std::uint32_t m_whizAudioId;                    // +0x0F0, exact CryAudio alias OPEN
    std::uint32_t m_trailAudioId;                   // +0x0F4, exact CryAudio alias OPEN
    std::uint32_t _padF8;                           // +0x0F8
    std::uint32_t m_ammoCost;                       // +0x0FC
    CryStringT<char> m_objectName;                  // +0x100
    EntityId m_ownerId;                             // +0x108
    std::uint32_t _pad10C;                          // +0x10C
    wh::framework::WUID m_sourceWuid;               // +0x110
    C_ItemWrapper m_itemWrapper;                    // +0x118
    float m_damageScale;                            // +0x130
    std::uint32_t _pad134;                          // +0x134
    IPhysicalEntity* m_pAuxiliaryPhysicalEntity;    // +0x138, owned; exact role OPEN
    std::int8_t m_bulletPierceabilityModifier;      // +0x140
    std::uint8_t m_currentPhysicsProfile;           // +0x141
    std::int8_t m_boundTracerIndex;                 // +0x142
    std::int8_t m_threatTrailTracerIndex;           // +0x143
    bool m_trailSoundEnabled;                       // +0x144
    bool m_automaticTrailEffect;                    // +0x145
    std::uint8_t _pad146[2];                        // +0x146
    boost::container::vector<EntityId> m_flyByNotifiedEntities; // +0x148
};
static_assert(sizeof(CProjectile) == 0x160, "CProjectile must be 0x160");
static_assert(offsetof(CProjectile, m_profileSignal) == 0x50,
              "profile signal must be at 0x50");
static_assert(offsetof(CProjectile, m_effects) == 0x78,
              "projectile effects must be at 0x78");
static_assert(offsetof(CProjectile, m_projectileFlags) == 0xA0,
              "projectile flags must be at 0xA0");
static_assert(offsetof(CProjectile, m_objectName) == 0x100,
              "projectile object name must be at 0x100");
static_assert(offsetof(CProjectile, m_itemWrapper) == 0x118,
              "projectile item wrapper must be at 0x118");
static_assert(offsetof(CProjectile, m_flyByNotifiedEntities) == 0x148,
              "fly-by entity vector must be at 0x148");

}  // namespace wh::entitymodule
