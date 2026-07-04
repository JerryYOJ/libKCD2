#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::S_PerkDefinitionId -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x10.
// -----------------------------------------------
// Perk identity value type (perk table rows). RTTR-proven: string type_converters exist
// (.?AU?$type_converter@US_PerkDefinitionId...), and every C_Perk ctor inits the id member
// @+0x10 with the 16-byte invalid constant xmmword_18409A0C0 (the invalid-id constant family
// next to S_LocationId's 0x18409A0B0). C_Perk::Resolve looks the id up in the global perk
// definition registry qword_18532E150; the secondary index qword_18532DD88 (32-byte rows) is
// searched by it too.
// INTERIOR TILING UNRESOLVED: two raw qwords (CryGUID-like pair candidate -- UNVERIFIED).

namespace wh::rpgmodule {

struct S_PerkDefinitionId {
    uint64_t m_raw[2];   // +0x00  16-byte compare; invalid = xmmword_18409A0C0
};
static_assert(sizeof(S_PerkDefinitionId) == 0x10, "S_PerkDefinitionId must be 0x10");

}  // namespace wh::rpgmodule
