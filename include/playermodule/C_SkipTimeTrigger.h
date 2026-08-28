#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"

namespace wh::playermodule {

class C_SkipTimeTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    C_SkipTimeTrigger();
    ~C_SkipTimeTrigger() override;                              // [0] 0x181FF77A0
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x181FF7D00
    void OnEffectActivate() override;                           // [43] 0x181FF7DE0
    void OnEffectDeactivate() override;                         // [44] 0x181FF7E40

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onStarted;              // +0xB0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onStopped;              // +0xF0
};

static_assert(sizeof(C_SkipTimeTrigger) == 0x130,
              "C_SkipTimeTrigger size mismatch");
static_assert(offsetof(C_SkipTimeTrigger, m_onStarted) == 0xB0,
              "C_SkipTimeTrigger started offset mismatch");
static_assert(offsetof(C_SkipTimeTrigger, m_onStopped) == 0xF0,
              "C_SkipTimeTrigger stopped offset mismatch");

} // namespace wh::playermodule
