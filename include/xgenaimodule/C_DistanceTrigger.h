#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/E_Operator.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_LinkableObject.h"

namespace wh::xgenaimodule {

class C_DistanceTrigger : public wh::conceptmodule::C_Effect {
public:
    ~C_DistanceTrigger() override;                                           // [0] 0x180967850
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                                 // [5..7], vtable 0x183A74550
    void OnEffectActivate() override;                                        // [43] 0x181693EE0
    void OnEffectDeactivate() override;                                      // [44] 0x18171A2EC

    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_origin;           // +0x88 RTTR "Origin"
    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_target;           // +0xC8 RTTR "Target"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::E_Operator> m_operator;                           // +0x108 RTTR "Operator"
    wh::conceptmodule::C_TypedPortRef<float> m_distance;                     // +0x148 RTTR "Distance"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onMatch;                             // +0x188 RTTR "OnMatch"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnmatch;                           // +0x1C8 RTTR "OnUnmatch"
    std::uint8_t m_unknown208[0x20];                                         // +0x208
};

static_assert(offsetof(C_DistanceTrigger, m_origin) == 0x88,
              "C_DistanceTrigger::m_origin offset mismatch");
static_assert(offsetof(C_DistanceTrigger, m_onUnmatch) == 0x1C8,
              "C_DistanceTrigger::m_onUnmatch offset mismatch");
static_assert(sizeof(C_DistanceTrigger) == 0x228,
              "C_DistanceTrigger size mismatch");

} // namespace wh::xgenaimodule
