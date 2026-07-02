#pragma once

// -----------------------------------------------
// wh::I_ReadinessDebuggable -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x8 (interface).
// -----------------------------------------------
// Root of the readiness-system task interface chain (RTTI: C_SaveGameManager CHD lists
// C_SaveGameManager : I_ReadinessTask : I_ReadinessDebuggable, all mdisp 0, single vtable).
// Contributes vtable slots [0] and [1] -- both nullsubs (0x1803B6E80) in C_SaveGameManager's
// vtable, i.e. default-empty debug hooks. Signatures/semantics UNRESOLVED; must NOT declare a
// virtual dtor (the shared vtable's deleting dtor sits at slot [5], after I_ReadinessTask's
// slots -- see I_ReadinessTask.h). Namespace read as wh:: (not wh::framework) from the RTTI.

namespace wh {

class I_ReadinessDebuggable {
public:
    virtual void DebugVf0() {}   // [0]  nullsub in C_SaveGameManager (name/signature UNRESOLVED)
    virtual void DebugVf1() {}   // [1]  nullsub in C_SaveGameManager (name/signature UNRESOLVED)
};
static_assert(sizeof(I_ReadinessDebuggable) == 0x8, "I_ReadinessDebuggable must be 0x8");

}  // namespace wh
