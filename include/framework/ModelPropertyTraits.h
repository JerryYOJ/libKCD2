#pragma once
#include <cstdint>
#include "C_Signal.h"

// -----------------------------------------------
// wh::shared::traits -- default-value / save-load policies of the C_ModelProperty family (kd7u).
// -----------------------------------------------
// Recovered from the RTTI of the S_CombatActorState property instantiations, e.g.
//   wh::shared::C_ModelProperty< E_CombatActorStateId::Type,
//                                wh::shared::traits::C_StaticDefaultValueTrait<...,1>,
//                                wh::combatmodule::traits::C_CombatSignalWithOldValueTrait<...>,
//                                wh::combatmodule::traits::C_CombatModelNoTrace,
//                                wh::shared::traits::C_NoSaveLoad,
//                                wh::combatmodule::traits::C_CombatActorModelOwnership >
// Standard/Static are empty policy objects; Custom stores one value at property+0x2C in the
// combat-owner layout (its _reserved word reproduces the 4-byte gap left at +0x28). Empty
// policy objects are still real data members in the generic ownerless layout and affect its size.

namespace wh::shared::traits {

// Default = T{} (zero); nothing stored.
template<class T>
struct C_StandardDefaultValueTrait {};

// Default = compile-time V (e.g. <int,-1>); nothing stored.
template<class T, T V>
struct C_StaticDefaultValueTrait {
    static constexpr T value = V;
};

// Default read from config/global at init; stored in the property at +0x2C.
template<class T>
struct C_CustomDefaultValueTrait {
    uint32_t _reserved;   // +0x00  (never written; keeps m_default at property+0x2C)
    T        m_default;   // +0x04
};

// No serialization; empty tag.
struct C_NoSaveLoad {};

// ---- GENERIC (non-combat) policy family, RTTI-named in C_Player/C_PlayerInteractor ----
// C_OwnershipEmpty removes the owner POINTER, not the policy members themselves. The empty Def,
// Trace, Save, and Own objects remain present in declaration order; their one-byte identities and
// the following signal alignment produce the observed 0x28/0x30/0x50 instantiation sizes.

// Broadcasts the new value; no owner argument (generic form).
template<class T>
struct C_SignalWithNewValueTrait {
    using Signal = wh::shared::C_Signal<T>;
};

// No debug tracing; empty tag (generic form; ToDbgStr returns the static empty string).
struct C_DebugNoTrace {};

// No stored owner pointer; empty policy object remains part of C_ModelProperty's layout.
struct C_OwnershipEmpty {};

}  // namespace wh::shared::traits
