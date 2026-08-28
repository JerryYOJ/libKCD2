#pragma once

#include "C_ActorStateTrigger.h"

namespace wh::entitymodule {

using C_ActorSkipTimeTriggerBase = C_ActorStateTrigger<E_ActorState::Type>;

class C_ActorSkipTimeTrigger : public C_ActorSkipTimeTriggerBase {
public:
    C_ActorSkipTimeTrigger();                                         // inlined in factories 0x182997C70 / 0x182998654
    ~C_ActorSkipTimeTrigger() override;                               // [0] 0x181546524
    RTTR_ENABLE(C_ActorSkipTimeTriggerBase)                           // [5..7], vtable 0x183E98390
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                  // [27] 0x1829A8D54
    E_ActorState::Type unk_47() override;                             // [47] 0x181A86DF0 returns skipTime
};

static_assert(sizeof(C_ActorSkipTimeTrigger) == 0x188,
              "C_ActorSkipTimeTrigger size mismatch");

} // namespace wh::entitymodule
