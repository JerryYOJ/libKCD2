#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>
#include "../framework/I_Action.h"
#include "I_ActorAction.h"
#include "C_ActorParamAction.h"
#include "S_ActorActionRiderParams.h"
#include "S_RiderActionPhase.h"
#include "C_RiderSync.h"

// -----------------------------------------------
// wh::entitymodule::C_ActorActionRider -- KCD2 WHGame.dll.  sizeof 0xA8.
// -----------------------------------------------
// : C_ActorParamAction<S_ActorActionRiderParams, I_ActorAction>
// Params at +0x50 (8). C_ActorObject at +0x58. Runtime +0x70..+0xA8.
// Factory sub_180AD40A0, ctor sub_180AD3E80, OnStart sub_180AA1474.

namespace wh::entitymodule {

class C_Actor;

class C_ActorActionRider
    : public C_ActorParamAction<S_ActorActionRiderParams, I_ActorAction> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ActorActionRider;
    C_Actor*                 m_pHorse;      // +0x70
    std::vector<wh::framework::I_Action*> m_subActions; // +0x78
    S_RiderActionPhase*      m_pState;      // +0x90  0x18 helper
    C_RiderSync*             m_pSync;       // +0x98
    int32_t                  m_zeroA0;      // +0xA0
    float                    m_elapsed;     // +0xA4  ctor FLT_MAX
};
static_assert(sizeof(C_ActorActionRider) == 0xA8, "C_ActorActionRider must be 0xA8");
static_assert(offsetof(C_ActorActionRider, m_params) == 0x50, "params");
static_assert(offsetof(C_ActorActionRider, m_pHorse) == 0x70, "horse");
static_assert(offsetof(C_ActorActionRider, m_pSync) == 0x98, "sync");

}  // namespace wh::entitymodule
