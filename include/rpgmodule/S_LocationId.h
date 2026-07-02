#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::S_LocationId -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x10 (INFERRED).
// -----------------------------------------------
// Location identity value type (location.xml rows). RTTI-proven usages: directly-stored member
// of C_Faction @+0x188 (RTTR property_wrapper member_object_ptr "LocationId"), RTTR
// type_converter to/from std::string (@0x184D529B0 / 0x184D53670), std::pair key
// (pair<S_LocationId, _smart_ptr<C_POI>>), and std::vector<S_LocationId> element.
// SIZE 0x10 is INFERRED from the C_Faction offset gap +0x188..+0x198 and the ctor's
// xmmword-zero init -- the vector element stride was NOT read to pin it exactly.
// INTERIOR TILING UNRESOLVED: represented as two raw qwords (likely {uint64 id, uint64 aux}
// or a CryGUID-like pair -- UNVERIFIED). Namespace placement inferred from its C_Faction /
// rpg-table usage (mangled-name backreference not expanded).

namespace wh::rpgmodule {

struct S_LocationId {
    uint64_t m_raw[2];   // +0x00  interior split UNRESOLVED (zero-init = invalid/none)
};
static_assert(sizeof(S_LocationId) == 0x10, "S_LocationId must be 0x10");

}  // namespace wh::rpgmodule
