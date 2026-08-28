#pragma once

#include <cstddef>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "S_ShieldIngredientName.h"

namespace wh::entitymodule {

class C_UnlockShieldIngredientEffect
    : public wh::conceptmodule::C_Effect {
public:
    C_UnlockShieldIngredientEffect();                                  // 0x181E9D2B0
    ~C_UnlockShieldIngredientEffect() override;                        // [0] 0x181E9DDF0
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                            // [5..7], vtable 0x183E90448
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                    // [27] 0x181E9E1F0
    void OnEffectActivate() override;                                  // [43] 0x181E9E2D0
    void OnEffectDeactivate() override;                                // [44] 0x181E9E380

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<S_ShieldIngredientName>> m_ingredients;             // +0x88 direct RTTR; source pin spelling unavailable
    wh::conceptmodule::C_TypedPortRef<bool> m_unlock;                   // +0xC8 direct RTTR; source pin spelling unavailable
};

static_assert(offsetof(C_UnlockShieldIngredientEffect, m_ingredients) == 0x88,
              "C_UnlockShieldIngredientEffect::m_ingredients offset mismatch");
static_assert(offsetof(C_UnlockShieldIngredientEffect, m_unlock) == 0xC8,
              "C_UnlockShieldIngredientEffect::m_unlock offset mismatch");
static_assert(sizeof(C_UnlockShieldIngredientEffect) == 0x108,
              "C_UnlockShieldIngredientEffect size mismatch");

} // namespace wh::entitymodule
