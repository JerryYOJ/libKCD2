#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/StackVector.h"
#include "CProjectile.h"
#include "S_DeferredArrowCollision.h"

namespace wh::entitymodule {

// KCD2 WHGame.dll 1.5.6: primary 0x183ECE6F0; allocation witness 0x182943FD0.
class CArrow : public CProjectile {
public:
    using DeferredCollisionQueue = std::StackVector<S_DeferredArrowCollision, 2>;

    inline static constexpr auto RTTI = Offsets::RTTI_CArrow;

    ~CArrow() override;                                                // [0] 0x182ACB3DC
    void ProcessEvent(SEntityEvent& event) override;                   // [1] 0x182ACD940
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] 0x182ACE924
    void HandleEvent(const SGameObjectEvent& event) override;          // [23] 0x182ACC7D4
    void _vf31() override;                                             // [31] 0x182ACDB24
    void Launch(const Vec3& position,
                const Vec3& direction,
                const Vec3& velocity,
                float speedScale) override;                            // [35] 0x182ACC880
    bool ShouldCollisionsDamageTarget() const override;                // [46] 0x18041A6A0
    bool HandleCollision(const EventPhysCollision& collision) override; // [47] 0x182ACBFA8
    void _vf49() override;                                             // [49] 0x182ACEAC8
    void _vf50(Offsets::IEntity* entity) override;                     // [50] 0x182ACD1E8

    EntityId m_attachedEntityId;             // +0x160
    std::uint32_t _pad164;                   // +0x164
    CryStringT<char> m_attachmentName;       // +0x168
    DeferredCollisionQueue m_deferredCollisions; // +0x170
    QuatT m_activeAttachmentTransform;       // +0x330
    volatile std::int32_t m_deferredCollisionLock; // +0x34C
};

using ArrowCollisionAllocator = std::StackAllocator<S_DeferredArrowCollision, 2>;
using ArrowCollisionVector = std::vector<
    S_DeferredArrowCollision,
    ArrowCollisionAllocator>;
using ArrowCollisionContainer = std::StackContainer<ArrowCollisionVector, 2>;

static_assert(sizeof(ArrowCollisionAllocator::Source) == 0x198,
              "arrow collision stack source must be 0x198");
static_assert(sizeof(ArrowCollisionAllocator) == 0x08,
              "arrow collision stack allocator must be 0x08");
static_assert(sizeof(ArrowCollisionVector) == 0x20,
              "arrow collision vector must be 0x20");
static_assert(sizeof(ArrowCollisionContainer) == 0x1C0,
              "arrow collision stack container must be 0x1C0");
static_assert(sizeof(CArrow::DeferredCollisionQueue) == 0x1C0,
              "arrow deferred-collision queue must be 0x1C0");
static_assert(sizeof(CArrow) == 0x350, "CArrow must be 0x350");
static_assert(offsetof(CArrow, m_attachmentName) == 0x168,
              "arrow attachment name must be at 0x168");
static_assert(offsetof(CArrow, m_deferredCollisions) == 0x170,
              "arrow collision queue must be at 0x170");
static_assert(offsetof(CArrow, m_activeAttachmentTransform) == 0x330,
              "arrow attachment transform must be at 0x330");
static_assert(offsetof(CArrow, m_deferredCollisionLock) == 0x34C,
              "arrow collision lock must be at 0x34C");

}  // namespace wh::entitymodule
