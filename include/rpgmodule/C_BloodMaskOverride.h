#pragma once
#include <cstddef>
#include <vector>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../entitymodule/clothing/S_BloodMaskName.h"
#include "I_Soul.h"

namespace wh::rpgmodule {

class C_BloodMaskOverride : public wh::conceptmodule::C_Effect {
public:
    C_BloodMaskOverride();
    ~C_BloodMaskOverride() override;                            // [0]
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27]
    void OnEffectActivate() override;                           // [43]
    void OnEffectDeactivate() override;                         // [44]

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<I_Soul*>> m_souls;                          // +0x88
    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::clothing::S_BloodMaskName> m_bloodMask; // +0xC8
};

static_assert(sizeof(C_BloodMaskOverride) == 0x108,
              "C_BloodMaskOverride size mismatch");
static_assert(offsetof(C_BloodMaskOverride, m_souls) == 0x88,
              "C_BloodMaskOverride souls offset mismatch");
static_assert(offsetof(C_BloodMaskOverride, m_bloodMask) == 0xC8,
              "C_BloodMaskOverride mask offset mismatch");

} // namespace wh::rpgmodule
