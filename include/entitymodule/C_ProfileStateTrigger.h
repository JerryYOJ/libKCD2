#pragma once

#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "S_LayerProfile.h"

namespace wh::entitymodule {

class C_ProfileStateTrigger : public wh::conceptmodule::C_Effect {
public:
    C_ProfileStateTrigger();                                           // 0x1810E019C
    ~C_ProfileStateTrigger() override;                                // [0] 0x180967B44
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                           // [5..7], vtable 0x183E9BD28
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                   // [27] 0x1829A951C
    void OnEffectActivate() override;                                 // [43] 0x180969494
    void OnEffectDeactivate() override;                               // [44] 0x180968E7C

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<S_LayerProfile>> m_profiles;                       // +0x88 RTTR "Profiles"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onLoaded;                      // +0xC8 RTTR "OnLoaded"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnloaded;                    // +0x108 RTTR "OnUnloaded"
    bool m_isListening;                                                // +0x148 profile load/unload callbacks connected
    std::uint8_t m_padding149[7];                                     // +0x149
    std::unordered_map<CryStringT<char>, bool> m_profileStates;       // +0x150 current loaded state by profile name
};

static_assert(offsetof(C_ProfileStateTrigger, m_profiles) == 0x88,
              "C_ProfileStateTrigger::m_profiles offset mismatch");
static_assert(offsetof(C_ProfileStateTrigger, m_onLoaded) == 0xC8,
              "C_ProfileStateTrigger::m_onLoaded offset mismatch");
static_assert(offsetof(C_ProfileStateTrigger, m_onUnloaded) == 0x108,
              "C_ProfileStateTrigger::m_onUnloaded offset mismatch");
static_assert(offsetof(C_ProfileStateTrigger, m_isListening) == 0x148,
              "C_ProfileStateTrigger::m_isListening offset mismatch");
static_assert(offsetof(C_ProfileStateTrigger, m_profileStates) == 0x150,
              "C_ProfileStateTrigger::m_profileStates offset mismatch");
static_assert(sizeof(C_ProfileStateTrigger) == 0x190,
              "C_ProfileStateTrigger size mismatch");

} // namespace wh::entitymodule
