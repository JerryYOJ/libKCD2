#pragma once
#include <cstddef>
#include <cstdint>
#include "C_PickableItem.h"

namespace wh::entitymodule {

// KCD2 WHGame.dll 1.5.6: primary 0x183B5AD28; allocation witness 0x181303334.
class C_MissileWeaponItem : public C_PickableItem {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_MissileWeaponItem;

    void ProcessEvent(SEntityEvent& event) override;                   // [1] 0x180EC42FC
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] 0x182A8B920
    std::uint32_t _vf129() const override;                             // [129] 0x181A72470, returns 1

    bool m_pendingRandomHitEffect;  // +0xD8
    bool m_pendingAttachment;       // +0xD9, target slot "slt_0"
    bool m_updateEnabled;           // +0xDA
    std::uint8_t _padDB;            // +0xDB
    EntityId m_attachmentTargetId;  // +0xDC
};
static_assert(sizeof(C_MissileWeaponItem) == 0xE0,
              "C_MissileWeaponItem must be 0xE0");
static_assert(offsetof(C_MissileWeaponItem, m_pendingRandomHitEffect) == 0xD8,
              "missile pending-effect state must be at 0xD8");
static_assert(offsetof(C_MissileWeaponItem, m_attachmentTargetId) == 0xDC,
              "missile attachment target must be at 0xDC");

}  // namespace wh::entitymodule
