#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::conceptmodule::C_EventNode<TBase> -- KCD2 WHGame.dll 1.5.6 (kd7u).  Adds 0x28 over TBase.
// -----------------------------------------------
// RTTI-proven template (instantiation seen: C_EventNode<C_Effect>, sizeof 0xB0 = C_Effect
// 0x88 + 0x28). Concept-graph "event node" intermediate: overrides the node-table slot
// [12] (rttr event-port value getter) with sub_18127FEA0 ("attempt to read data from
// event port '%s' outside of event trigger execution") and appends ONE extra node-table
// virtual at slot [46] (0x18061A490, shared) -- neither is modeled as a C++ virtual per
// module convention. Bases of C_ApseViewTrigger / C_InteractorOverride.
// The 0x28 member block is ctor-zeroed; field roles UNVERIFIED (event-trigger execution
// state).

namespace wh::conceptmodule {

template <typename TBase>
class C_EventNode : public TBase {
public:
    uint8_t m_eventNodeState[0x28];   // +sizeof(TBase)  ctor-zeroed event-execution state [roles UNVERIFIED]
};

}  // namespace wh::conceptmodule
