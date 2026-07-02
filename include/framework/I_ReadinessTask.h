#pragma once
#include "I_ReadinessDebuggable.h"

// -----------------------------------------------
// wh::I_ReadinessTask : I_ReadinessDebuggable -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x8.
// -----------------------------------------------
// Readiness-system task interface (a task the readiness system waits on / notifies, e.g. the
// "AfterGameLoad" gate). Contributes vtable slots [2..4]; in C_SaveGameManager these hold
// sub_1825BD8B4 / sub_181A76C10 / sub_181A76C30 (override-vs-inherited-default not
// distinguished; names UNRESOLVED). The virtual dtor is declared LAST so the deleting dtor
// lands at slot [5], matching the observed 6-slot vtable -- WHICH class in the chain actually
// declares the dtor (this one vs the concrete task) is UNVERIFIED; this placement reproduces
// the binary slot order.

namespace wh {

class I_ReadinessTask : public I_ReadinessDebuggable {
public:
    virtual void TaskVf2() {}            // [2]  C_SaveGameManager: sub_1825BD8B4 (UNRESOLVED)
    virtual void TaskVf3() {}            // [3]  C_SaveGameManager: sub_181A76C10 (UNRESOLVED)
    virtual void TaskVf4() {}            // [4]  C_SaveGameManager: sub_181A76C30 (UNRESOLVED)
    virtual ~I_ReadinessTask() = default;   // [5]  deleting dtor slot
};
static_assert(sizeof(I_ReadinessTask) == 0x8, "I_ReadinessTask must be 0x8");

}  // namespace wh
