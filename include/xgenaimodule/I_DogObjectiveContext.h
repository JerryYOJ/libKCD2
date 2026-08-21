#pragma once
#include "../Offsets/Offsets_RTTI.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::I_DogObjectiveContext
// (KCD2 WHGame.dll 1.5.6). sizeof 0x8. 8 pure slots, no virtual dtor.
// -----------------------------------------------
// RTTI .?AVI_DogObjectiveContext@activitysystem@xgenaimodule@wh@@
// Abstract table 0x183B1F268. Concrete C_DogCompanionContext+8 0x183A81D48.
// Stored at C_DogObjective+0x70. Not a parent of the objective.

namespace wh::xgenaimodule::activitysystem {

class I_DogObjectiveContext {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_DogObjectiveContext;

    virtual void* GetDogObject() = 0;          // [0] 0x180626640
    virtual void* GetCompanion() = 0;          // [1] 0x18213D640
    virtual void* unk_02() = 0;                // [2] 0x180A49DA0
    virtual void* GetObjectivePack() = 0;      // [3] 0x1809F6CD0  ctx+0x908
    virtual void* GetMaster() = 0;             // [4] 0x1809DD2D0
    virtual void* unk_05() = 0;                // [5] 0x180396800
    virtual void* GetCommandQueue() = 0;       // [6] 0x1809F6CC0  ctx+0x1D88
    virtual void* unk_07() = 0;                // [7] 0x1809F6CC0
};
static_assert(sizeof(I_DogObjectiveContext) == 0x08,
              "I_DogObjectiveContext is vptr-only");

}  // namespace wh::xgenaimodule::activitysystem
