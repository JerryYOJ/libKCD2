#pragma once
#include <cstddef>
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_SoulPropertyTrigger.h"

namespace wh::rpgmodule {

class C_SoulDeathTrigger : public C_SoulPropertyTrigger {
public:
    C_SoulDeathTrigger();
    ~C_SoulDeathTrigger() override;                              // [0]
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
        wh::conceptmodule::S_Trigger> m_onAllDeath;              // +0x1C8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onDeath;                 // +0x208
};

static_assert(sizeof(C_SoulDeathTrigger) == 0x248,
              "C_SoulDeathTrigger size mismatch");
static_assert(offsetof(C_SoulDeathTrigger, m_onAllDeath) == 0x1C8,
              "C_SoulDeathTrigger all-death offset mismatch");
static_assert(offsetof(C_SoulDeathTrigger, m_onDeath) == 0x208,
              "C_SoulDeathTrigger death offset mismatch");

} // namespace wh::rpgmodule
