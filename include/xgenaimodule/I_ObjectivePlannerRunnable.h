#pragma once
#include "../Offsets/Offsets_RTTI.h"
#include "S_ObjectiveScore.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::I_ObjectivePlannerRunnable
// (KCD2 WHGame.dll 1.5.6). sizeof 0x8. 3 slots.
// -----------------------------------------------
// RTTI .?AVI_ObjectivePlannerRunnable@activitysystem@xgenaimodule@wh@@
// vtable 0x183A42D48. [1][2] _purecall until C_ActivityObjective.

namespace wh::xgenaimodule::activitysystem {

class I_ObjectivePlannerRunnable {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ObjectivePlannerRunnable;

    virtual ~I_ObjectivePlannerRunnable() = default;               // [0] 0x1832F81D0
    virtual S_ObjectiveScore* GetScore(S_ObjectiveScore* out) = 0; // [1] 0x181D93E5D
    virtual void Start(void* session) = 0;                         // [2] 0x181D93E5D
};
static_assert(sizeof(I_ObjectivePlannerRunnable) == 0x08,
              "I_ObjectivePlannerRunnable is vptr-only");

}  // namespace wh::xgenaimodule::activitysystem
