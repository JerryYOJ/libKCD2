#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "E_SaveLockEffectReason.h"

namespace wh::playermodule {

class C_SaveLockEffect : public wh::conceptmodule::C_Effect {
public:
    C_SaveLockEffect();
    ~C_SaveLockEffect() override;                               // [0] 0x1815A52CC
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DE090C
    void OnEffectActivate() override;                           // [43] 0x182DE1410
    void OnEffectDeactivate() override;                         // [44] 0x182DE1A8C

    wh::conceptmodule::C_TypedPortRef<
        E_SaveLockEffectReason::Type> m_lockReason;             // +0x88
};

static_assert(sizeof(C_SaveLockEffect) == 0xC8,
              "C_SaveLockEffect size mismatch");
static_assert(offsetof(C_SaveLockEffect, m_lockReason) == 0x88,
              "C_SaveLockEffect reason offset mismatch");

} // namespace wh::playermodule
