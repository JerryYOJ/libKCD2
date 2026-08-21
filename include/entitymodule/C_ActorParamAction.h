#pragma once
#include "../framework/C_ParamAction.h"
#include "../framework/C_Action.h"
#include "C_ActorAction.h"

// -----------------------------------------------
// wh::entitymodule::C_ActorParamAction<TParams, TIface>
// -----------------------------------------------
// : C_ActorAction<TIface, C_ParamAction<TParams, C_Action<TIface>>>
// Adds no data. C_ActorActionRider's 0x38 tail is on the leaf.

namespace wh::entitymodule {

template<class TParams, class TIface>
class C_ActorParamAction
    : public C_ActorAction<TIface, wh::framework::C_ParamAction<TParams, wh::framework::C_Action<TIface>>> {
};

}  // namespace wh::entitymodule
