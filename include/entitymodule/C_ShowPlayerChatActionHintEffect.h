#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../framework/C_LocalizedString.h"

namespace wh::entitymodule {

class C_ShowPlayerChatActionHintEffect
    : public wh::conceptmodule::C_Effect {
public:
    C_ShowPlayerChatActionHintEffect();                                  // 0x1810D57F8
    ~C_ShowPlayerChatActionHintEffect() override;                        // [0] 0x181889C04
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                             // [5..7], vtable 0x183B06B20
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                     // [27] 0x18295F27C
    void OnEffectActivate() override;                                   // [43] 0x18295F65C
    void OnEffectDeactivate() override;                                 // [44] 0x18295F9B8

    wh::conceptmodule::C_TypedPortRef<
        wh::framework::C_LocalizedString> m_actionPrompt;                // +0x88 RTTR "ActionPrompt"
    bool m_isHintShown;                                                  // +0xC8 owns the process-global hint while set
    std::uint8_t m_paddingC9[7];                                        // +0xC9
};

static_assert(offsetof(C_ShowPlayerChatActionHintEffect, m_actionPrompt) == 0x88,
              "C_ShowPlayerChatActionHintEffect::m_actionPrompt offset mismatch");
static_assert(offsetof(C_ShowPlayerChatActionHintEffect, m_isHintShown) == 0xC8,
              "C_ShowPlayerChatActionHintEffect::m_isHintShown offset mismatch");
static_assert(sizeof(C_ShowPlayerChatActionHintEffect) == 0xD0,
              "C_ShowPlayerChatActionHintEffect size mismatch");

} // namespace wh::entitymodule
