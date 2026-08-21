#pragma once
#include "../Offsets/Offsets_RTTI.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::I_ActivityObjectiveContext
// (KCD2 WHGame.dll 1.5.6). sizeof 0x8. 4 slots, no virtual dtor.
// -----------------------------------------------
// RTTI .?AVI_ActivityObjectiveContext@activitysystem@xgenaimodule@wh@@
// Pure table 0x183B1F550. Concrete C_ActivitySystemContext+8 0x183FEE218.
// Stored at C_ActivityObjective+0x18 (C_DogObjective ctor 0x1806265D8).

namespace wh::xgenaimodule::activitysystem {

class I_ActivityObjectiveContext {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ActivityObjectiveContext;

    virtual void* unk_00() = 0;  // [0] 0x18213D5E0  C_ActivitySystemContext+0x28
    virtual void* unk_01() = 0;  // [1] 0x181A84670  C_ActivitySystemContext+0x168
    virtual void* GetNPC() = 0;  // [2] 0x18213D5F8  *(context+0x20) C_NPC*  [SYNTHETIC NAME]
    virtual void* unk_03() = 0;  // [3] 0x180396820  dog C_Actor::m_pActionActor
};
static_assert(sizeof(I_ActivityObjectiveContext) == 0x08,
              "I_ActivityObjectiveContext is vptr-only");

}  // namespace wh::xgenaimodule::activitysystem
