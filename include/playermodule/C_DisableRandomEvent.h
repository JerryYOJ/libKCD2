#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "S_RandomEventTag.h"

namespace wh::playermodule {

class C_DisableRandomEvent : public wh::conceptmodule::C_Effect {
public:
    C_DisableRandomEvent();
    ~C_DisableRandomEvent() override;                            // [0] 0x181528060
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182EAD63C
    void OnEffectActivate() override;                           // [43] 0x18074AADC
    void OnEffectDeactivate() override;                         // [44] 0x18074AB38

    wh::conceptmodule::C_TypedPortRef<
        S_RandomEventTag> m_randomEventTag;                     // +0x88
};

static_assert(sizeof(C_DisableRandomEvent) == 0xC8,
              "C_DisableRandomEvent size mismatch");
static_assert(offsetof(C_DisableRandomEvent, m_randomEventTag) == 0x88,
              "C_DisableRandomEvent tag offset mismatch");

} // namespace wh::playermodule
