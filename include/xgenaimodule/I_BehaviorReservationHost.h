#pragma once

// -----------------------------------------------
// wh::xgenaimodule::I_BehaviorReservationHost
// (KCD2 WHGame.dll 1.5.6). vptr-only, 2 slots, no virtual dtor.
// -----------------------------------------------
// RTTI .?AVI_BehaviorReservationHost@xgenaimodule@wh@@ (TD 0x184E8E4B0, CHD 0x1844CE978).
// No standalone complete-object vtable/COL exists in the binary -- the only
// installed instance is the secondary (subobject) table on C_FunOnSoDogObjective,
// stamped at that class's +0xE8 (BCD mdisp=0xE8, COL 0x1840DD098 offset=232).
// See C_FunOnSoDogObjective.h / C_FunOnTargetBaseDogObjective.md AUDIT2 for the MI proof.
//
// Slot names are UNVERIFIED -- kept as unk_NN rather than guessed:
//   [0] FunOnSo's secondary-table impl 0x18330AC70 is a this-adjustor thunk
//       (this-0xE8) into 0x1809F4E08, the SAME body C_FunOnTargetBaseDogObjective's
//       own StopIfRunning [4] calls as its first step. Narrower than a full
//       StopIfRunning call (skips the FunOnTargetBase-specific teardown), so it is
//       deliberately NOT named StopIfRunning here.
//   [1] FunOnSo's secondary-table impl is 0x180838AE0 (return false) -- the
//       codebase-wide default-false stub, gives no behavioral hint.

namespace wh::xgenaimodule {

struct I_BehaviorReservationHost {
    virtual void unk_00() = 0;  // [0] FunOnSo secondary-vtable impl 0x18330AC70 (this-adjustor -> 0x1809F4E08)
    virtual bool unk_01() = 0;  // [1] FunOnSo secondary-vtable impl 0x180838AE0 (return false)
};

}  // namespace wh::xgenaimodule
