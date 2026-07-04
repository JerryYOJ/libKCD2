#pragma once

// -----------------------------------------------
// wh::conceptmodule::C_AutoTriggerable<TBase> -- auto-trigger mixin (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// Only instantiation seen: C_AutoTriggerable<C_Node> (base of conceptmodule::C_Effect).
// Ctor sub_1806B2130: TBase ctor, own vftable, then ORs bit 1 into the C_SharedResource flag
// word at +0x0E.  Adds NO data members (derived conceptmodule::C_Effect members start at
// +0x40 = sizeof(C_Node)).

namespace wh::conceptmodule {

template <typename TBase>
class C_AutoTriggerable : public TBase {
public:
};

}  // namespace wh::conceptmodule
