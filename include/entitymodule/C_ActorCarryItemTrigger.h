#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_ActorStateTrigger.h"

namespace wh::entitymodule {

class C_CarryItemPile;
using C_ActorCarryItemTriggerBase = C_ActorStateTrigger<E_ActorState::Type>;

class C_ActorCarryItemTrigger : public C_ActorCarryItemTriggerBase {
public:
    C_ActorCarryItemTrigger();                                         // 0x1810D53EC
    ~C_ActorCarryItemTrigger() override;                               // [0] 0x181546488
    RTTR_ENABLE(C_ActorCarryItemTriggerBase)                           // [5..7], vtable 0x183B05938
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                   // [27] 0x1829A8A14
    void OnEffectActivate() override;                                 // [43] 0x180D7B094
    E_ActorState::Type unk_47() override;                             // [47] 0x181A86DD0 returns carryItem
    void unk_48() override;                                           // [48] 0x18189FADC
    void unk_49() override;                                           // [49] 0x18199B490

    C_CarryItemPile* m_activePile;                                    // +0x188 borrowed matching pile
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onDropped;                     // +0x190 RTTR "OnDropped"
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<C_CarryItemPile*>> m_sourcePiles;                  // +0x1D0 RTTR "SourcePiles"
    std::vector<std::int32_t> m_sourcePileIds;                        // +0x210 activation-time pile IDs
};

static_assert(offsetof(C_ActorCarryItemTrigger, m_activePile) == 0x188,
              "C_ActorCarryItemTrigger::m_activePile offset mismatch");
static_assert(offsetof(C_ActorCarryItemTrigger, m_onDropped) == 0x190,
              "C_ActorCarryItemTrigger::m_onDropped offset mismatch");
static_assert(offsetof(C_ActorCarryItemTrigger, m_sourcePiles) == 0x1D0,
              "C_ActorCarryItemTrigger::m_sourcePiles offset mismatch");
static_assert(offsetof(C_ActorCarryItemTrigger, m_sourcePileIds) == 0x210,
              "C_ActorCarryItemTrigger::m_sourcePileIds offset mismatch");
static_assert(sizeof(C_ActorCarryItemTrigger) == 0x228,
              "C_ActorCarryItemTrigger size mismatch");

} // namespace wh::entitymodule
