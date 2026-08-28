#pragma once

#include "C_ActorStateTrigger.h"

namespace wh::entitymodule {

using C_ActorSprintTriggerBase = C_ActorStateTrigger<E_ActorState::Type>;

class C_ActorSprintTrigger : public C_ActorSprintTriggerBase {
public:
    C_ActorSprintTrigger();                                           // inlined in factories 0x1810D549C / 0x182997D24
    ~C_ActorSprintTrigger() override;                                 // [0] 0x181546524
    RTTR_ENABLE(C_ActorSprintTriggerBase)                             // [5..7], vtable 0x183E98528
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                  // [27] 0x1829A8E24
    E_ActorState::Type unk_47() override;                             // [47] 0x1808BE9F0 returns sprinting
};

static_assert(sizeof(C_ActorSprintTrigger) == 0x188,
              "C_ActorSprintTrigger size mismatch");

} // namespace wh::entitymodule
