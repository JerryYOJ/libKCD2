#pragma once

// -----------------------------------------------
// wh::game::I_EntitySideEffectCallback -- KCD2 WHGame.dll 1.5.6 (kd7u).
// -----------------------------------------------
// Callback interface for entity side-effect completion. Secondary MI base of
// combatmodule::C_CombatAutomationWeapons (RTTI-confirmed, mdisp 0x38; its 2-slot vtable at
// 0x183B0A260 points both slots at the same handler sub_182767740 -- the second slot is presumed
// the dtor thunk collapsed by ICF; slot split tentative).

namespace wh::game {

class I_EntitySideEffectCallback {
public:
    virtual ~I_EntitySideEffectCallback() = default;              // [0] (ICF-folded with [1])
    virtual void OnEntitySideEffect(void* sideEffect) = 0;        // [1] sub_182767740
};

}  // namespace wh::game
