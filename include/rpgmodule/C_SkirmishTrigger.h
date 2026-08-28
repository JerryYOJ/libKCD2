#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "E_SkirmishEventType.h"
#include "I_SkirmishListener.h"
#include "I_Soul.h"
#include "S_SkirmishStatistics.h"

namespace wh::rpgmodule {

class I_SkirmishHandle;
class I_SkirmishHandleProvider;

class C_SkirmishTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>,
      public I_SkirmishListener {
public:
    C_SkirmishTrigger();
    ~C_SkirmishTrigger() override;                                // primary [0]
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // primary [5..7]
    rttr::variant GetPortValue(
        const _smart_ptr<wh::conceptmodule::I_Port>& port) override; // primary [12]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                               // primary [27]
    void OnEffectActivate() override;                             // primary [43]
    void OnEffectDeactivate() override;                           // primary [44]

    void OnSkirmishStarted(
        I_SkirmishHandleProvider* skirmish,
        std::uint32_t matchFlag) override;                        // secondary [1]
    void OnSkirmishEnded() override;                              // secondary [2]

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<I_Soul*>> m_souls;                            // +0xB8
    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_referenceSoul;   // +0xF8
    wh::conceptmodule::C_TypedPortRef<
        E_SkirmishEventType::Type> m_eventType;                   // +0x138
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onEvent;                  // +0x178
    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_eventSoul;       // +0x1B8
    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_eventTargetSoul; // +0x1F8
    wh::conceptmodule::C_TypedPortRef<
        S_SkirmishStatistics*> m_statistics;                      // +0x238
    I_Soul* m_resolvedReferenceSoul;                              // +0x278
    E_SkirmishEventType::Type m_resolvedEventType;                // +0x280
    bool m_listenerRegistered;                                   // +0x281
    std::uint8_t m_padding282[6];                                // +0x282
    I_SkirmishHandle* m_skirmishHandle;                           // +0x288
};

static_assert(sizeof(C_SkirmishTrigger) == 0x290,
              "C_SkirmishTrigger size mismatch");
static_assert(offsetof(C_SkirmishTrigger, m_souls) == 0xB8,
              "C_SkirmishTrigger souls offset mismatch");
static_assert(offsetof(C_SkirmishTrigger, m_eventType) == 0x138,
              "C_SkirmishTrigger event-type offset mismatch");
static_assert(offsetof(C_SkirmishTrigger, m_statistics) == 0x238,
              "C_SkirmishTrigger statistics offset mismatch");
static_assert(offsetof(C_SkirmishTrigger, m_resolvedReferenceSoul) == 0x278,
              "C_SkirmishTrigger resolved-reference offset mismatch");
static_assert(offsetof(C_SkirmishTrigger, m_skirmishHandle) == 0x288,
              "C_SkirmishTrigger handle offset mismatch");

} // namespace wh::rpgmodule
