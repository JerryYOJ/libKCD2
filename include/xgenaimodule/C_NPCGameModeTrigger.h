#pragma once

#include <cstddef>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"

namespace wh::rpgmodule {
class I_Soul;
}

namespace wh::xgenaimodule {

class C_NPCGameModeTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    C_NPCGameModeTrigger();                                                  // 0x18158A2C8
    ~C_NPCGameModeTrigger() override;                                        // [0] 0x1832805FC
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<
        wh::conceptmodule::C_Effect>)                                        // [5..7], vtable 0x183C04D90
    void OnEffectActivate() override;                                        // [43] 0x18328299C
    void OnEffectDeactivate() override;                                      // [44] 0x183282C88

    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_npcSoul;                                   // +0xB0 RTTR "NPCSoul"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onGameModeStartTrigger;              // +0xF0 RTTR "OnGameModeStartTrigger"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onGameModeEndTrigger;                // +0x130 RTTR "OnGameModeEndTrigger"
};

static_assert(offsetof(C_NPCGameModeTrigger, m_npcSoul) == 0xB0,
              "C_NPCGameModeTrigger::m_npcSoul offset mismatch");
static_assert(offsetof(C_NPCGameModeTrigger, m_onGameModeStartTrigger) == 0xF0,
              "C_NPCGameModeTrigger::m_onGameModeStartTrigger offset mismatch");
static_assert(offsetof(C_NPCGameModeTrigger, m_onGameModeEndTrigger) == 0x130,
              "C_NPCGameModeTrigger::m_onGameModeEndTrigger offset mismatch");
static_assert(sizeof(C_NPCGameModeTrigger) == 0x170,
              "C_NPCGameModeTrigger size mismatch");

} // namespace wh::xgenaimodule
