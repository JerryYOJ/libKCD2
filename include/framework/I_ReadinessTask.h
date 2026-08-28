#pragma once
#include <cstdint>
#include "I_ReadinessDebuggable.h"

// -----------------------------------------------
// wh::I_ReadinessTask : I_ReadinessDebuggable -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x8.
// -----------------------------------------------
// Readiness-system task interface (a task the readiness system waits on / notifies, e.g. the
// "AfterGameLoad" gate). Contributes vtable slots [2..4]; in C_SaveGameManager these hold
// sub_1825BD8B4 / sub_181A76C10 / sub_181A76C30 (override-vs-inherited-default not
// distinguished; names UNRESOLVED).
//
// The chain is DTOR-LESS (5 vfuncs total): PROVEN by C_XGenAIModule, where I_ReadinessTask is
// a secondary base (+0x18) and its subobject vtable 0x184012f88 has exactly 5 slots, no dtor
// (an interface dtor would force a 6th slot in every subobject vtable). C_SaveGameManager's
// observed slot [5] deleting dtor is C_SaveGameManager's OWN dtor, appended to its primary
// vtable because readiness is its primary base -- declared there, not here.

namespace wh {

class I_ReadinessTask : public I_ReadinessDebuggable {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ReadinessTask;
    virtual bool TaskVf2() { return false; }               // [2] readiness predicate
    virtual std::uint32_t TaskVf3() { return 0; }          // [3] readiness value
    virtual const void* TaskVf4() { return nullptr; }      // [4] runtime descriptor
};
static_assert(sizeof(I_ReadinessTask) == 0x8, "I_ReadinessTask must be 0x8");

}  // namespace wh
