#pragma once
#include "../framework/C_Signal.h"

namespace wh::combatmodule { class I_CombatActor; }

namespace wh::combatmodule::traits {

template<class T, class... Extra>
struct C_CombatSignalWithNewValueTrait {
    using Signal = wh::shared::C_Signal<I_CombatActor&, T, Extra...>;
};

template<class T>
struct C_CombatSignalWithOldValueTrait {
    using Signal = wh::shared::C_Signal<I_CombatActor&, T, T>;
};

template<class T, class IndexEnum>
struct C_CombatSignalArrayTrait {
    using ElementSignal = wh::shared::C_Signal<I_CombatActor&, IndexEnum, T>;
    using AggregateSignal = wh::shared::C_Signal<I_CombatActor&, bool>;
};

template<class T>
struct C_CombatSignalSetTrait {
    using Signal = wh::shared::C_Signal<I_CombatActor&, const T&, bool>;
};

struct C_CombatModelNoTrace {};

struct C_CombatActorModelOwnership {
    using OwnerPtr = wh::combatmodule::I_CombatActor*;
};

}  // namespace wh::combatmodule::traits
