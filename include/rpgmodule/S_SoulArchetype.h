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
    uint32_t _pad0C;        // +0x0C
    const char* m_name;     // +0x10  I_DynamicEnum::GetName reads row+0x10
    uint8_t  _unk18[0x40];  // +0x18  no reader decompiled [UNVERIFIED]
};
static_assert(sizeof(S_SoulArchetype) == 0x58, "S_SoulArchetype must be 0x58 (I_DynamicEnum stride 88)");

}  // namespace wh::rpgmodule
