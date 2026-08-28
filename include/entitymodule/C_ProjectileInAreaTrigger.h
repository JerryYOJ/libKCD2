#pragma once

#include <cstddef>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "I_ProjectileAreaDetectionListener.h"

namespace wh::xgenaimodule {
class I_Area;
}

namespace wh::entitymodule {

class C_ProjectileInAreaTrigger
    : public wh::conceptmodule::C_Effect,
      public I_ProjectileAreaDetectionListener {
public:
    C_ProjectileInAreaTrigger();                                        // 0x181613488
    ~C_ProjectileInAreaTrigger() override;                              // [0] 0x181947048
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                             // [5..7], vtable 0x183BD5F88
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                     // [27] 0x1829A95EC
    void OnEffectActivate() override;                                   // [43] 0x1829A99FC
    void OnEffectDeactivate() override;                                 // [44] 0x1829A9D80

    void OnProjectileDetected() override;                               // +0x88 [0] 0x1829A9ED4

    wh::conceptmodule::C_TypedPortRef<
        wh::xgenaimodule::I_Area*> m_area;                              // +0x90 RTTR "Area"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onProjectile;                   // +0xD0 RTTR "OnProjectile"
    wh::xgenaimodule::I_Area* m_activeArea;                             // +0x110 borrowed registration key
};

static_assert(offsetof(C_ProjectileInAreaTrigger, m_area) == 0x90,
              "C_ProjectileInAreaTrigger::m_area offset mismatch");
static_assert(offsetof(C_ProjectileInAreaTrigger, m_onProjectile) == 0xD0,
              "C_ProjectileInAreaTrigger::m_onProjectile offset mismatch");
static_assert(offsetof(C_ProjectileInAreaTrigger, m_activeArea) == 0x110,
              "C_ProjectileInAreaTrigger::m_activeArea offset mismatch");
static_assert(sizeof(C_ProjectileInAreaTrigger) == 0x118,
              "C_ProjectileInAreaTrigger size mismatch");

} // namespace wh::entitymodule
