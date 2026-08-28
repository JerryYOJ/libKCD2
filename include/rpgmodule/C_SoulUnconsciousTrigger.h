#pragma once
#include <cstddef>
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_SoulPropertyTrigger.h"

namespace wh::rpgmodule {

class C_SoulUnconsciousTrigger : public C_SoulPropertyTrigger {
public:
    C_SoulUnconsciousTrigger();
    ~C_SoulUnconsciousTrigger() override;                        // [0]
    RTTR_ENABLE(C_SoulPropertyTrigger) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                              // [27]
    void OnAggregateStateChanged(
        bool allMatching,
        bool noneMatching) override;                             // [47]
    void OnSoulStateChanged(
        I_Soul* soul,
        bool matching) override;                                // [48]

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllUnconscious;        // +0x1C8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnconscious;           // +0x208
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllConscious;          // +0x248
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onConscious;             // +0x288
};

static_assert(sizeof(C_SoulUnconsciousTrigger) == 0x2C8,
              "C_SoulUnconsciousTrigger size mismatch");
static_assert(offsetof(C_SoulUnconsciousTrigger, m_onAllUnconscious) == 0x1C8,
              "C_SoulUnconsciousTrigger all-unconscious offset mismatch");
static_assert(offsetof(C_SoulUnconsciousTrigger, m_onUnconscious) == 0x208,
              "C_SoulUnconsciousTrigger unconscious offset mismatch");
static_assert(offsetof(C_SoulUnconsciousTrigger, m_onAllConscious) == 0x248,
              "C_SoulUnconsciousTrigger all-conscious offset mismatch");
static_assert(offsetof(C_SoulUnconsciousTrigger, m_onConscious) == 0x288,
              "C_SoulUnconsciousTrigger conscious offset mismatch");

} // namespace wh::rpgmodule
