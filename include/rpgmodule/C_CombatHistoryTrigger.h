#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_CombatHistorySignal.h"
#include "I_Soul.h"

namespace wh::rpgmodule {

class C_CombatHistoryTrigger : public wh::conceptmodule::C_Effect {
public:
    C_CombatHistoryTrigger();
    ~C_CombatHistoryTrigger() override;                           // [0]
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                               // [27]
    void OnEffectActivate() override;                             // [43]
    void OnEffectDeactivate() override;                           // [44]

    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_soul1;          // +0x88 RTTR "Soul1"
    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_soul2;          // +0xC8 RTTR "Soul2"
    wh::conceptmodule::C_TypedPortRef<float> m_unknownFloat;      // +0x108 duplicate RTTR "Soul2"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onCombatHistoryBegins;    // +0x148
    C_CombatHistorySignal m_signal;                               // +0x188
};

static_assert(sizeof(C_CombatHistoryTrigger) == 0x1B8,
              "C_CombatHistoryTrigger size mismatch");
static_assert(offsetof(C_CombatHistoryTrigger, m_soul1) == 0x88,
              "C_CombatHistoryTrigger Soul1 offset mismatch");
static_assert(offsetof(C_CombatHistoryTrigger, m_unknownFloat) == 0x108,
              "C_CombatHistoryTrigger float offset mismatch");
static_assert(offsetof(C_CombatHistoryTrigger, m_signal) == 0x188,
              "C_CombatHistoryTrigger signal offset mismatch");

} // namespace wh::rpgmodule
