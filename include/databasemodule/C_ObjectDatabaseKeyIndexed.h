#pragma once

// -----------------------------------------------
// wh::databasemodule::C_ObjectDatabaseKeyIndexed<TBase, TExtractor> -- single-key index
// decorator (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI-proven template; decorates both stacks: over C_ObjectTableDatabase (e.g. the
// combatmodule C_CombatWeaponCombinationData database) and over C_ObjectTreeDatabase (e.g.
// C_SoulStateEffectContextDatabase), always paired with C_ObjectDatabaseDefaultKeyExtractor<Row>.
// MEMBER LAYOUT UNRESOLVED: the observed ctors (sub_180F9F018) write only the vftable at this
// layer -- any index storage is zero-init (global statics) and invisible to ctor analysis.
// Declares NO members; must not be used for sizeof math.

namespace wh::databasemodule {

template <typename TBase, typename TExtractor>
class C_ObjectDatabaseKeyIndexed : public TBase {
public:
};

}  // namespace wh::databasemodule
