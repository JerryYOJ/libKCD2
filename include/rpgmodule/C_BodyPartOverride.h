#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../entitymodule/clothing/S_CharacterComponentName.h"
#include "E_BodyPart.h"
#include "I_Soul.h"

namespace wh::rpgmodule {

class C_BodyPartOverride : public wh::conceptmodule::C_Effect {
public:
    C_BodyPartOverride();
    ~C_BodyPartOverride() override;                             // [0]
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27]
    void OnEffectActivate() override;                           // [43]
    void OnEffectDeactivate() override;                         // [44]

    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_soul;         // +0x88
    wh::conceptmodule::C_TypedPortRef<E_BodyPart::Type> m_bodyPart; // +0xC8
    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::clothing::S_CharacterComponentName>
        m_component;                                            // +0x108
};

static_assert(sizeof(C_BodyPartOverride) == 0x148,
              "C_BodyPartOverride size mismatch");
static_assert(offsetof(C_BodyPartOverride, m_soul) == 0x88,
              "C_BodyPartOverride soul offset mismatch");
static_assert(offsetof(C_BodyPartOverride, m_bodyPart) == 0xC8,
              "C_BodyPartOverride body-part offset mismatch");
static_assert(offsetof(C_BodyPartOverride, m_component) == 0x108,
              "C_BodyPartOverride component offset mismatch");

} // namespace wh::rpgmodule
