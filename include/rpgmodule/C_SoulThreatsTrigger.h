#pragma once
#include <cstddef>
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_SoulPropertyTrigger.h"

namespace wh::rpgmodule {

class C_SoulThreatsTrigger : public C_SoulPropertyTrigger {
public:
    C_SoulThreatsTrigger();
    ~C_SoulThreatsTrigger() override;                            // [0]
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
        wh::conceptmodule::S_Trigger> m_onAllThreatsActive;      // +0x1C8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onThreatsActive;         // +0x208
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllThreatsInactive;    // +0x248
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onThreatsInactive;       // +0x288
};

static_assert(sizeof(C_SoulThreatsTrigger) == 0x2C8,
              "C_SoulThreatsTrigger size mismatch");
static_assert(offsetof(C_SoulThreatsTrigger, m_onAllThreatsActive) == 0x1C8,
              "C_SoulThreatsTrigger all-active offset mismatch");
static_assert(offsetof(C_SoulThreatsTrigger, m_onThreatsActive) == 0x208,
              "C_SoulThreatsTrigger active offset mismatch");
static_assert(offsetof(C_SoulThreatsTrigger, m_onAllThreatsInactive) == 0x248,
              "C_SoulThreatsTrigger all-inactive offset mismatch");
static_assert(offsetof(C_SoulThreatsTrigger, m_onThreatsInactive) == 0x288,
              "C_SoulThreatsTrigger inactive offset mismatch");

} // namespace wh::rpgmodule
