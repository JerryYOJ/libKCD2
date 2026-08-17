#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/vtables/IEntity.h"
#include "SHitAuxContext.h"

struct HitInfo {
    EntityId shooterId;              // +0x00
    EntityId targetId;               // +0x04
    EntityId weaponId;               // +0x08
    EntityId projectileId;           // +0x0C
    float damage;                    // +0x10
    float impulseScale;              // +0x14
    float radius;                    // +0x18
    float angle;                     // +0x1C
    std::int32_t material;           // +0x20
    std::int32_t type;               // +0x24
    std::int32_t bulletType;         // +0x28
    float damageMin;                 // +0x2C
    std::int32_t partId;             // +0x30
    Vec3 pos;                        // +0x34
    Vec3 dir;                        // +0x40
    Vec3 normal;                     // +0x4C
    std::uint16_t projectileClassId; // +0x58
    std::uint16_t weaponClassId;     // +0x5A
    std::int32_t ammoClassId;        // +0x5C
    bool remote;                     // +0x60
    bool aimed;                      // +0x61, stock-order name inferred
    bool knocksDown;                 // +0x62, stock-order name inferred
    bool knocksDownLeg;              // +0x63, stock-order name inferred
    bool hitViaProxy;                // +0x64, stock-order name inferred
    bool explosion;                  // +0x65, stock-order name inferred
    bool forceLocalKill;             // +0x66, stock-order name inferred
    std::byte _pad67;                // +0x67
    std::int32_t m_unknown68;        // +0x68, semantics OPEN
    std::byte _pad6C[0x04];          // +0x6C
    SHitAuxContext* m_pContext;      // +0x70, non-owning
};
static_assert(sizeof(HitInfo) == 0x78, "HitInfo must be 0x78");
static_assert(offsetof(HitInfo, ammoClassId) == 0x5C,
              "ammo class ID must be at 0x5C");
static_assert(offsetof(HitInfo, remote) == 0x60,
              "remote flag must be at 0x60");
static_assert(offsetof(HitInfo, m_unknown68) == 0x68,
              "open hit tail must be at 0x68");
static_assert(offsetof(HitInfo, m_pContext) == 0x70,
              "hit context must be at 0x70");
