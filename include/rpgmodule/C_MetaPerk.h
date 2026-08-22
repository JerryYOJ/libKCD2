#pragma once
#include <cstdint>
#include <vector>
#include "C_Perk.h"
#include "S_PerkDefinitionId.h"

// -----------------------------------------------
// wh::rpgmodule::C_MetaPerk -- perk that groups child perks (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI .?AVC_MetaPerk@rpgmodule@wh@@ (TD 0x184D53E50)  vtable 0x183B68B78.
// sizeof 0x60 (PROVEN: factory sub_18136F388 operator new(96)).
// Ctor zeroes +0x30..+0x5F as two std::vector.  Activate [1] (0x180A1FFD4) walks
// m_childIds (16-byte GUID stride) or, when a source meta is passed, copies each
// source child's m_id @+0x10.  GetChildPerks [5] (0x181A73940) returns &m_childPerks
// -- that is the vector native HasPerk walks for nested perks.

namespace wh::rpgmodule {

class C_MetaPerk : public C_Perk {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_MetaPerk;

    const std::vector<C_Perk*>* GetChildPerks() const;  // [5] +0x28  0x181A73940  returns &m_childPerks

    std::vector<S_PerkDefinitionId> m_childIds;    // +0x30  GUID list (Activate fallback, stride 0x10)
    std::vector<C_Perk*>            m_childPerks;  // +0x48  live child instances (HasPerk / Activate)
};
static_assert(sizeof(C_MetaPerk) == 0x60, "C_MetaPerk must be 0x60 (operator new(96))");
static_assert(offsetof(C_MetaPerk, m_childIds) == 0x30, "child GUIDs at 0x30");
static_assert(offsetof(C_MetaPerk, m_childPerks) == 0x48, "child perks at 0x48");

}  // namespace wh::rpgmodule
