#pragma once

// -----------------------------------------------
// wh::animationmodule::I_SceneListener -- animation scene event listener
// (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0x08 (vtable only).
// -----------------------------------------------
// RTTI .?AVI_SceneListener@animationmodule@wh@@. Modelled minimally, from the C_CombatScene
// subobject that implements it (base at +0x08; subobject vtable 0x183A6C7A0 = 2 slots: [0] dtor
// thunk sub_1821392BC, [1] the listener callback -- a nop sub_1803B6E80 in C_CombatScene). Method
// name is KCD1-correlated [inferred]; only the slot count is proven.

namespace wh::animationmodule {

class I_SceneListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_SceneListener;
    virtual ~I_SceneListener() = default;     // [0]
    virtual void OnSceneChanged() = 0;        // [1]  (name inferred from KCD1)
};

}  // namespace wh::animationmodule
