#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "E_BattleEvent.h"
#include "S_BattleSituation.h"

namespace wh::rpgmodule { class I_Soul; }
namespace wh::xgenaimodule { class C_SmartObject; }

namespace wh::combatmodule {

class C_BattleTrigger
    : public wh::conceptmodule::C_EventNode<
          wh::conceptmodule::C_Effect> {
public:
    ~C_BattleTrigger() override;                               // [0] 0x182777754
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<
        wh::conceptmodule::C_Effect>)                          // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                     // [27] 0x18277D8AC
    void OnEffectActivate() override;                          // [43] 0x18277DD9C
    void OnEffectDeactivate() override;                        // [44] 0x18277E3D0

    wh::conceptmodule::C_TypedPortRef<
        wh::xgenaimodule::C_SmartObject*> m_smartObject;       // +0xB0 RTTR "SmartObject"
    wh::conceptmodule::C_TypedPortRef<
        E_BattleEvent::Type> m_eventType;                      // +0xF0 RTTR "EventType"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onEvent;               // +0x130 RTTR "OnEvent"
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_eventSoul;                   // +0x170 RTTR "EventSoul"
    wh::conceptmodule::C_TypedPortRef<
        S_BattleSituation*> m_situation;                       // +0x1B0 RTTR "Situation"
    std::uint32_t m_eventSourceId;                             // +0x1F0 callback filter key
};

static_assert(offsetof(C_BattleTrigger, m_smartObject) == 0xB0,
              "C_BattleTrigger::m_smartObject offset mismatch");
static_assert(offsetof(C_BattleTrigger, m_eventType) == 0xF0,
              "C_BattleTrigger::m_eventType offset mismatch");
static_assert(offsetof(C_BattleTrigger, m_onEvent) == 0x130,
              "C_BattleTrigger::m_onEvent offset mismatch");
static_assert(offsetof(C_BattleTrigger, m_eventSoul) == 0x170,
              "C_BattleTrigger::m_eventSoul offset mismatch");
static_assert(offsetof(C_BattleTrigger, m_situation) == 0x1B0,
              "C_BattleTrigger::m_situation offset mismatch");
static_assert(offsetof(C_BattleTrigger, m_eventSourceId) == 0x1F0,
              "C_BattleTrigger::m_eventSourceId offset mismatch");
static_assert(sizeof(C_BattleTrigger) == 0x1F8,
              "C_BattleTrigger size mismatch");

}  // namespace wh::combatmodule
