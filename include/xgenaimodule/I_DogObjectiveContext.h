#pragma once
#include "../Offsets/Offsets_RTTI.h"
#include "../entitymodule/I_ActionActorExpansion.h"
#include "I_ActivityObjectiveContext.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::I_DogObjectiveContext
// (KCD2 WHGame.dll 1.5.6). sizeof 0x8. 8 pure slots, no virtual dtor.
// -----------------------------------------------
// RTTI .?AVI_DogObjectiveContext@activitysystem@xgenaimodule@wh@@
// Pure table 0x183B1F268. Concrete C_DogCompanionContext+8 0x183A81D48
// (embed at C_DogCompanion+0x10, not a Companion base).
// Stored at C_DogObjective+0x70.
// [1][2][3][4] stay void*: no complete-object RTTI / GetMaster is a QI result.

namespace wh::xgenaimodule::activitysystem {

class C_ObjectivePlanner;    // pack+0x1480 (C_DogCompanionContext+0x1D90)
class C_DogObjectivePack;    // no .?AV; embed at C_DogCompanionContext+0x910, sizeof 0x14D8

class I_DogObjectiveContext {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_DogObjectiveContext;

    virtual I_ActivityObjectiveContext* GetActivityObjectiveContext() = 0;          // [0] 0x180626640  *(ctx+0x30)+8
    virtual void* unk_01() = 0;                                                     // [1] 0x18213D640  ctx+0x38 hub
    virtual void* unk_02() = 0;                                                     // [2] 0x180A49DA0  ctx+0x3D0 pack
    virtual C_DogObjectivePack* GetObjectivePack() = 0;                             // [3] 0x1809F6CD0  ctx+0x910
    virtual void* GetMaster() = 0;                                                  // [4] 0x1809DD2D0  *(ctx+0x20) QI [U]
    virtual wh::entitymodule::I_ActionActorExpansion* GetDogExpansion() = 0;        // [5] 0x180396800  GetExpansion(Dog)
    virtual C_ObjectivePlanner* GetObjectivePlanner() = 0;                          // [6] 0x1809F6CC0  ctx+0x1D90
    virtual C_ObjectivePlanner* GetObjectivePlannerForEnqueue() = 0;                // [7] ICF same body/member as [6]
};
static_assert(sizeof(I_DogObjectiveContext) == 0x08,
              "I_DogObjectiveContext is vptr-only");

}  // namespace wh::xgenaimodule::activitysystem
