#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_StateProxy.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../questmodule/S_Tracker.h"
#include "../rpgmodule/I_Soul.h"
#include "E_MinigameTutorialDomain.h"

namespace wh::playermodule {

using C_MinigameTutorialNodeBase =
    wh::conceptmodule::C_StateProxy<
        wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>>;

class C_MinigameTutorialNode : public C_MinigameTutorialNodeBase {
public:
    C_MinigameTutorialNode();
    ~C_MinigameTutorialNode() override;                         // [0] 0x18178EDB4
    RTTR_ENABLE(C_MinigameTutorialNodeBase) // [5..7]
    rttr::variant GetPortValue(
        _smart_ptr<wh::conceptmodule::I_Port> const& port) override; // [12] 0x182DDF324
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x1812BCCC0
    void OnExecute(
        wh::conceptmodule::S_NodeExecuteContext const& context) override; // [33] 0x182DDF050
    void OnEffectActivate() override;                           // [43] 0x182DE12A8
    void OnEffectDeactivate() override;                         // [44] 0x182DE1990

    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_tutor;                       // +0xB8
    wh::conceptmodule::C_TypedPortRef<
        E_MinigameTutorialDomain::Type> m_domain;              // +0xF8
    wh::conceptmodule::C_TypedPortRef<std::int32_t> m_initialPhase; // +0x138
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onTutorialEnd;         // +0x178
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onPhaseStart;          // +0x1B8
    wh::conceptmodule::C_TypedPortRef<std::int32_t> m_phase;   // +0x1F8
    wh::conceptmodule::C_TypedPortRef<
        wh::questmodule::S_Tracker> m_tracker;                 // +0x238
    wh::questmodule::S_Tracker m_trackerState;                 // +0x278 role unresolved
};

static_assert(sizeof(C_MinigameTutorialNode) == 0x288,
              "C_MinigameTutorialNode size mismatch");
static_assert(offsetof(C_MinigameTutorialNode, m_tutor) == 0xB8,
              "C_MinigameTutorialNode tutor offset mismatch");
static_assert(offsetof(C_MinigameTutorialNode, m_tracker) == 0x238,
              "C_MinigameTutorialNode tracker offset mismatch");
static_assert(offsetof(C_MinigameTutorialNode, m_trackerState) == 0x278,
              "C_MinigameTutorialNode tracker state offset mismatch");

} // namespace wh::playermodule
