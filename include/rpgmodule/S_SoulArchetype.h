#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::S_SoulArchetype -- soul_archetype table row (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI .?AUS_SoulArchetype@rpgmodule@wh@@ (TD 0x184D415C8; polymorphic -- own vtable 0x183B52798).
// Row type of C_SoulArchetypeDatabase (C_ObjectDatabaseIdIndexed stack with an I_DynamicEnum
// view). Row stride 0x58 (PROVEN: the I_DynamicEnum impls index the row array with *88).
// Only the enum-view fields are typed (value @+0x08, name @+0x10); the rest is unread in the
// decompiled surface. The vfptr slot count is NOT enumerated.

namespace wh::rpgmodule {

struct S_SoulArchetype {
    inline static constexpr auto RTTI = Offsets::RTTI_S_SoulArchetype;
    virtual ~S_SoulArchetype() = 0;   // +0x00 vfptr (slot set NOT enumerated; abstract in this mirror)

    int32_t  m_id;          // +0x08  I_DynamicEnum::GetValue reads row+0x08
    std::uint8_t _pad0C[4]; // +0x0C
    CryStringT<char> m_name;  // +0x10  RTTR member_object_ptr CryStringT<char> (GetName returns its char*)
    wh::entitymodule::E_Race::Type m_race; // +0x18  ctor default -1 (index/id sentinel; loader copies DBData+0x10)
    std::int32_t m_genderId; // +0x1C  ctor default 4 (small int/enum)
    float m_normalBodyWeight; // +0x20  ctor default 1.0f (SSE-init lane0 @xmmword_18409EE30)
    float m_bodyBaseArmor; // +0x24  ctor default 0.0f (SSE block +0x20..+0x2F) [float inferred]
    float m_bodyBaseVisibility; // +0x28  ctor default 0.0f (SSE block) [float inferred]
    float m_bodyBaseConspicuousness; // +0x2C  ctor default 0.0f (SSE block) [float inferred]
    float m_inventoryCapacityMultiplier; // +0x30  ctor default 0 [int/float ambiguous]
    float m_baseStamina; // +0x34  ctor default 100.0f
    float m_relativeVitalityToStamina; // +0x38  ctor default 100.0f
    bool m_needsHomeLink; // +0x3C  1-byte field (bool candidate; loader copies DBData+0x34)
    std::uint8_t _pad3D[3]; // +0x3D  align pad
    float m_unarmedAttackBase; // +0x40  ctor fmaxf(0,x) clamp>=0; loader parses via sub_1823D9D34
    float m_jumpCostModifier; // +0x44  ctor default 0 [int/float ambiguous]
    float m_badassnessBias; // +0x48  ctor default 0 [int/float ambiguous]
    float m_attackDistanceOptimal; // +0x4C  ctor default 0 [int/float ambiguous]
    float m_attackDistanceMax; // +0x50  ctor default 0 [int/float ambiguous]
    std::uint8_t _pad54[4]; // +0x54  tail pad to 0x58 (not copied by copy-ctor)
};
static_assert(sizeof(S_SoulArchetype) == 0x58, "S_SoulArchetype must be 0x58 (I_DynamicEnum stride 88)");

}  // namespace wh::rpgmodule
