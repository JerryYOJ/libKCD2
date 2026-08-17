#pragma once
#include <cstddef>
#include <cstdint>
#include <type_traits>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/vtables/IEntity.h"

// Current 0xA0 hit-history/script record; canonical native type name remains open.
struct SExpandedHitRecord {
    EntityId attackerId;                    // +0x00
    std::byte m_open04[0x04];               // +0x04
    std::uint64_t m_projectileIdentity;     // +0x08, exact identity type OPEN
    std::int32_t m_recordClassId;           // +0x10, default 21
    std::int32_t m_auxiliary14;             // +0x14
    std::int32_t hitTypeId;                 // +0x18
    std::int32_t ammoClassId;               // +0x1C
    std::int32_t m_auxiliary20;             // +0x20
    std::uint8_t m_mode24;                  // +0x24, default 2
    std::byte m_open25[0x03];               // +0x25
    EntityId targetId;                      // +0x28
    float m_derivedValue2C;                 // +0x2C
    float damage;                           // +0x30
    std::int32_t targetOriginalMaterialId;  // +0x34
    std::int32_t materialId;                // +0x38
    std::int32_t partId;                    // +0x3C
    bool m_flag40;                          // +0x40
    bool m_flag41;                          // +0x41
    std::byte m_open42[0x02];               // +0x42
    std::int32_t hitStrength;               // +0x44
    std::int32_t m_auxiliary48;             // +0x48
    std::int32_t m_auxiliary4C;             // +0x4C
    Vec3 pos;                               // +0x50
    Vec3 dir;                               // +0x5C
    Vec3 normal;                            // +0x68
    bool isStabbed;                         // +0x74
    bool m_flag75;                          // +0x75
    bool m_flag76;                          // +0x76
    std::byte m_open77;                     // +0x77
    std::uint32_t m_stateWord78;            // +0x78, default 63
    std::int32_t m_attackerValue0;          // +0x7C
    std::int32_t m_attackerValue1;          // +0x80
    std::int32_t m_targetValue0;            // +0x84
    std::int32_t m_targetValue1;            // +0x88
    std::byte m_zeroInitialized8C[0x10];    // +0x8C
    std::byte m_tail9C[0x04];               // +0x9C
};
static_assert(sizeof(SExpandedHitRecord) == 0xA0,
              "SExpandedHitRecord must be 0xA0");
static_assert(offsetof(SExpandedHitRecord, targetId) == 0x28,
              "expanded-hit target must be at 0x28");
static_assert(offsetof(SExpandedHitRecord, pos) == 0x50,
              "expanded-hit position must be at 0x50");
static_assert(offsetof(SExpandedHitRecord, dir) == 0x5C,
              "expanded-hit direction must be at 0x5C");
static_assert(offsetof(SExpandedHitRecord, normal) == 0x68,
              "expanded-hit normal must be at 0x68");
static_assert(offsetof(SExpandedHitRecord, m_stateWord78) == 0x78,
              "expanded-hit state word must be at 0x78");
static_assert(std::is_trivially_copyable_v<SExpandedHitRecord>,
              "SExpandedHitRecord must be trivially copyable");
