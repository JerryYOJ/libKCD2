#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"
#include "../xgenaimodule/C_LinkableObject.h"
#include "S_SkaldAtlTriggerId.h"

namespace wh::soundmodule {

class C_AudioSustainedEffect : public wh::conceptmodule::C_Effect {
public:
    ~C_AudioSustainedEffect() override;                     // [0] 0x1815F0910
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                   // [27] 0x182F04878
    void OnEffectActivate() override;                        // [43] 0x182F049F0
    void OnEffectDeactivate() override;                      // [44] 0x182F04A04

    wh::conceptmodule::C_TypedPortRef<S_SkaldAtlTriggerId> m_atlTriggerName; // +0x88
    wh::conceptmodule::C_TypedPortRef<wh::xgenaimodule::C_LinkableObject*> m_linkableObject; // +0xC8
};

static_assert(offsetof(C_AudioSustainedEffect, m_atlTriggerName) == 0x88,
              "C_AudioSustainedEffect::m_atlTriggerName offset mismatch");
static_assert(offsetof(C_AudioSustainedEffect, m_linkableObject) == 0xC8,
              "C_AudioSustainedEffect::m_linkableObject offset mismatch");
static_assert(sizeof(C_AudioSustainedEffect) == 0x108,
              "C_AudioSustainedEffect size mismatch");

}  // namespace wh::soundmodule
