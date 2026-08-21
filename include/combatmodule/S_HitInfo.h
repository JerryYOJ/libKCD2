#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace wh::combatmodule {

struct S_HitInfo {
    EntityId       attackerId;               // +0x00
    std::byte      _pad04[4];                // +0x04
    std::uint64_t  sourceWuid;               // +0x08
    std::int32_t   itemTypeId;               // +0x10
    std::int32_t   attackerMaterialId;       // +0x14
    std::int32_t   hitTypeId;                // +0x18
    std::int32_t   ammoClassId;              // +0x1C
    std::int32_t   combatDataId;             // +0x20
    std::uint8_t   weaponMode;               // +0x24
    std::byte      _pad25[3];                // +0x25
    EntityId       targetId;                 // +0x28
    float          staminaDamage;            // +0x2C
    float          damage;                   // +0x30
    std::int32_t   targetOriginalMaterialId; // +0x34
    std::int32_t   materialId;               // +0x38
    std::int32_t   partId;                   // +0x3C
    bool           causedDeath;              // +0x40
    bool           causedUnconsciousness;    // +0x41
    std::byte      _pad42[2];                // +0x42
    std::int32_t   hitStrength;              // +0x44
    std::int32_t   fallbackAttackerId;       // +0x48
    std::int32_t   fallbackPartId;           // +0x4C
    Vec3           pos;                      // +0x50
    Vec3           dir;                      // +0x5C
    Vec3           normal;                   // +0x68
    bool           isStabbed;                // +0x74
    bool           _reserved75;              // +0x75
    bool           _reserved76;              // +0x76
    std::byte      _pad77;                   // +0x77
    std::uint32_t  stateWord;                // +0x78
    std::int32_t   attackerItemSlot0;        // +0x7C
    std::int32_t   attackerItemSlot1;        // +0x80
    std::int32_t   targetItemSlot0;          // +0x84
    std::int32_t   targetItemSlot1;          // +0x88
    std::array<std::uint8_t, 16> destroyedItemId; // +0x8C
    std::byte      _pad9C[4];                // +0x9C
};
static_assert(sizeof(S_HitInfo) == 0xA0);
static_assert(offsetof(S_HitInfo, targetId) == 0x28);
static_assert(offsetof(S_HitInfo, causedDeath) == 0x40);
static_assert(offsetof(S_HitInfo, pos) == 0x50);
static_assert(offsetof(S_HitInfo, stateWord) == 0x78);
static_assert(offsetof(S_HitInfo, destroyedItemId) == 0x8C);
static_assert(std::is_trivially_copyable_v<S_HitInfo>);

}  // namespace wh::combatmodule
