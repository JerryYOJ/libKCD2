#pragma once
#include <cstddef>
#include <functional>
#include <memory>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_StateProxy.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../questmodule/S_Tracker.h"
#include "E_CombatTutorialDomain.h"

namespace wh::rpgmodule { class I_Soul; }

namespace wh::combatmodule {

class C_CombatTutorialNode
    : public wh::conceptmodule::C_StateProxy<
          wh::conceptmodule::C_EventNode<
              wh::conceptmodule::C_Effect>> {
public:
    ~C_CombatTutorialNode() override;                          // [0] 0x18178EDE8
    RTTR_ENABLE(wh::conceptmodule::C_StateProxy<
        wh::conceptmodule::C_EventNode<
            wh::conceptmodule::C_Effect>>)                     // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                     // [27] 0x181758E80
    void GetPortDefinitions(
        wh::conceptmodule::definition::PortDefinitionSink sink,
        bool includeAll) override;                                   // [28] 0x180F4249C
    void OnExecute(
        wh::conceptmodule::S_NodeExecuteContext const& context) override; // [33] 0x1819D48CC
    void OnEffectActivate() override;                          // [43] 0x18277DE24
    void OnEffectDeactivate() override;                        // [44] 0x18277E3D8

    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_tutor;                       // +0xB8 RTTR "Tutor"
    wh::conceptmodule::C_TypedPortRef<
        E_CombatTutorialDomain::Type> m_domain;                // +0xF8 RTTR "Domain"
    wh::conceptmodule::C_TypedPortRef<int> m_initialPhase;     // +0x138 RTTR "InitialPhase"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onTutorialEnd;         // +0x178 RTTR "OnTutorialEnd"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onPhaseStart;          // +0x1B8 RTTR "OnPhaseStart"
    wh::conceptmodule::C_TypedPortRef<int> m_phase;            // +0x1F8 RTTR "Phase"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onSuccessEvent;        // +0x238 RTTR "OnSuccessEvent"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onFailEvent;           // +0x278 RTTR "OnFailEvent"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onPhaseSkipped;        // +0x2B8 RTTR "OnPhaseSkipped"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_customStepEvent;       // +0x2F8 RTTR "CustomStepEvent"
    wh::conceptmodule::C_TypedPortRef<
        wh::questmodule::S_Tracker> m_tracker;                 // +0x338 RTTR "Tracker"
    wh::questmodule::S_Tracker m_trackerState;                 // +0x378 runtime progress
};

static_assert(offsetof(C_CombatTutorialNode, m_tutor) == 0xB8,
              "C_CombatTutorialNode::m_tutor offset mismatch");
static_assert(offsetof(C_CombatTutorialNode, m_initialPhase) == 0x138,
              "C_CombatTutorialNode::m_initialPhase offset mismatch");
static_assert(offsetof(C_CombatTutorialNode, m_phase) == 0x1F8,
              "C_CombatTutorialNode::m_phase offset mismatch");
static_assert(offsetof(C_CombatTutorialNode, m_customStepEvent) == 0x2F8,
              "C_CombatTutorialNode::m_customStepEvent offset mismatch");
static_assert(offsetof(C_CombatTutorialNode, m_tracker) == 0x338,
              "C_CombatTutorialNode::m_tracker offset mismatch");
static_assert(offsetof(C_CombatTutorialNode, m_trackerState) == 0x378,
              "C_CombatTutorialNode::m_trackerState offset mismatch");
static_assert(sizeof(C_CombatTutorialNode) == 0x388,
              "C_CombatTutorialNode size mismatch");

}  // namespace wh::combatmodule
