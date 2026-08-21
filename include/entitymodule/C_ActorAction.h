#pragma once
#include "../framework/C_Action.h"
#include "C_ActorObject.h"

// -----------------------------------------------
// wh::entitymodule::C_ActorAction<TIface, TBase> -- TBase + C_ActorObject.
// -----------------------------------------------
// TBase = C_Action<TIface> => object @+0x50, sizeof 0x68.
// TBase = C_ParamAction<Params, C_Action<TIface>> => object @+0x58, sizeof 0x70.
// Adds primary slot GetDebugDetail after C_Action's tail.

namespace wh::entitymodule {

template<class TIface, class TBase>
class C_ActorAction : public TBase, public C_ActorObject {
public:
    virtual void* GetDebugDetail(void* out) { return out; }  // [46] on I_ActorAction inst
};

}  // namespace wh::entitymodule
