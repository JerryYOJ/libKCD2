#pragma once

#include "C_ActorStateTrigger.h"

namespace wh::entitymodule {

using C_ActorFollowTriggerBase = C_ActorStateTrigger<E_ActorState::Type>;

class C_ActorFollowTrigger : public C_ActorFollowTriggerBase {
public:
    C_ActorFollowTrigger();                                           // inlined in factories 0x182997B18 / 0x182998598
    ~C_ActorFollowTrigger() override;                                 // [0] 0x181546524
    RTTR_ENABLE(C_ActorFollowTriggerBase)                             // [5..7], vtable 0x183E98858
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                  // [27] 0x1829A8BB4
    E_ActorState::Type unk_47() override;                             // [47] 0x181A86DE0 returns follow
};

static_assert(sizeof(C_ActorFollowTrigger) == 0x188,
              "C_ActorFollowTrigger size mismatch");

} // namespace wh::entitymodule
