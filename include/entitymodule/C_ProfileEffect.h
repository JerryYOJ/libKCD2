#pragma once

#include <cstddef>
#include <unordered_map>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "S_LayerProfile.h"

namespace wh::entitymodule {

class C_ProfileEffect : public wh::conceptmodule::C_Effect {
public:
    C_ProfileEffect();                                                  // 0x1811283C4
    ~C_ProfileEffect() override;                                       // [0] 0x180967C80
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                            // [5..7], vtable 0x183E90680
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                    // [27] 0x18295F1AC
    std::int32_t MapEventToPhase(std::int32_t event) override;          // [35] 0x181394A88
    void PropagateToPorts(bool propagate) override;                    // [40] 0x18153B2FC
    void OnEffectActivate() override;                                  // [43] 0x180969728
    void OnEffectDeactivate() override;                                // [44] 0x1814ECFE0

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<S_LayerProfile>> m_profiles;                        // +0x88 RTTR "Profiles"
    std::unordered_map<CryStringT<char>, void*> m_activeProfiles;       // +0xC8 owning polymorphic values; interface type unresolved
};

static_assert(offsetof(C_ProfileEffect, m_profiles) == 0x88,
              "C_ProfileEffect::m_profiles offset mismatch");
static_assert(offsetof(C_ProfileEffect, m_activeProfiles) == 0xC8,
              "C_ProfileEffect::m_activeProfiles offset mismatch");
static_assert(sizeof(C_ProfileEffect) == 0x108,
              "C_ProfileEffect size mismatch");

} // namespace wh::entitymodule
