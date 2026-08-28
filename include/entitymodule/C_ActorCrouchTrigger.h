#pragma once

#include "C_ActorStateTrigger.h"

namespace wh::entitymodule {

using C_ActorCrouchTriggerBase = C_ActorStateTrigger<E_ActorIdleState::Type>;

class C_ActorCrouchTrigger : public C_ActorCrouchTriggerBase {
public:
    C_ActorCrouchTrigger();                                           // inlined in factories 0x18160A10C / 0x182997A64
    ~C_ActorCrouchTrigger() override;                                // [0] 0x1816C8628
    RTTR_ENABLE(C_ActorCrouchTriggerBase)                             // [5..7], vtable 0x183E986C0
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                  // [27] 0x1829A8AE4
    E_ActorIdleState::Type unk_47() override;                         // [47] 0x18041A6A0 returns value 1
};

static_assert(sizeof(C_ActorCrouchTrigger) == 0x188,
              "C_ActorCrouchTrigger size mismatch");

} // namespace wh::entitymodule
