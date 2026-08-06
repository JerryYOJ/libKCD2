#pragma once
#include <cstdint>
#include "../conceptmodule/C_Effect.h"

// -----------------------------------------------
// wh::entitymodule::C_DisableAlchemyTable -- concept/flow node disabling alchemy tables
// (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI .?AVC_DisableAlchemyTable@entitymodule@wh@@ (TD 0x184BDED30); vtable 0x183C2D3A0.
// CORRECTED 2026-08-05: this is the standard 46-slot C_Effect node table, not a bespoke
// 14-slot shape ([40] 0x1813E804C, [41] 0x1806B1478, [45] nullsub match every other
// C_Effect derivative). Holds its target tables as a reflected
// C_TypedArrayPortRef<std::vector<C_AlchemyTable*>> input port "AlchemyTables" at +0x88.
// TOGGLE PATH CORRECTED: OnEffectActivate [43] 0x18295F5D8 resolves AlchemyTables into a
// std::vector<C_AlchemyTable*> at +0xC8 and directly ++'s a disable COUNTER at
// C_AlchemyTable+0x40 for each element (0 = enabled); OnEffectDeactivate [44] 0x18295F8E4
// --'s the same counter and clears the vector. No reflected property_wrapper::set is
// involved (the prior "generic RTTR reflected iterate" claim was wrong).
// [Own member layout beyond the AlchemyTables port offset UNVERIFIED; no sizeof static_assert.]

namespace wh::entitymodule {

class C_DisableAlchemyTable : public wh::conceptmodule::C_Effect {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DisableAlchemyTable;
};

}  // namespace wh::entitymodule
