#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "S_GameOverId.h"

namespace wh::playermodule {

class C_GameOverTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    C_GameOverTrigger();
    ~C_GameOverTrigger() override;                              // [0] 0x18192581C
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DE04F4
    void OnEffectActivate() override;                           // [43] 0x180613C9C
    void OnEffectDeactivate() override;                         // [44] 0x180613738

    wh::conceptmodule::C_TypedPortRef<S_GameOverId> m_reason;   // +0xB0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onGameOver;             // +0xF0
    S_GameOverId m_resolvedReason;                              // +0x130
    std::uint32_t m_padding134;                                // +0x134
};

static_assert(sizeof(C_GameOverTrigger) == 0x138,
              "C_GameOverTrigger size mismatch");
static_assert(offsetof(C_GameOverTrigger, m_reason) == 0xB0,
              "C_GameOverTrigger reason offset mismatch");
static_assert(offsetof(C_GameOverTrigger, m_resolvedReason) == 0x130,
              "C_GameOverTrigger resolved reason offset mismatch");

} // namespace wh::playermodule
