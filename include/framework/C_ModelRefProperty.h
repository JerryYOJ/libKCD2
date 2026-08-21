#pragma once
#include "C_ModelProperty.h"

// -----------------------------------------------
// wh::shared::C_ModelRefProperty<Sig,Trace,Own> -- KCD2 1.5.6 (kd7u).  sizeof 0x30.
// -----------------------------------------------
// IS-A C_ModelProperty<int> and adds no storage. The stored int at +0x08 is an
// activation count; ref-property writers emit false/true only across the 0<->1 boundary.

namespace wh::shared {

template<class Sig   = wh::combatmodule::traits::C_CombatSignalWithNewValueTrait<int>,
         class Trace = wh::combatmodule::traits::C_CombatModelNoTrace,
         class Own   = wh::combatmodule::traits::C_CombatActorModelOwnership>
class C_ModelRefProperty
    : public C_ModelProperty<int, traits::C_StandardDefaultValueTrait<int>, Sig, Trace,
                             traits::C_NoSaveLoad, Own> {
};
static_assert(sizeof(C_ModelRefProperty<>) == 0x30, "C_ModelRefProperty must be 0x30");

}  // namespace wh::shared
