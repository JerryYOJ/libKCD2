#pragma once

#include <cstddef>

#include "../conceptmodule/C_TypedPortRef.h"
#include "C_ActorStateTrigger.h"

namespace wh::entitymodule {

using C_ActorMountedTriggerBase = C_ActorStateTrigger<E_ActorMountState::Type>;

class C_ActorMountedTrigger : public C_ActorMountedTriggerBase {
public:
    C_ActorMountedTrigger();                                           // 0x18146DD88
    ~C_ActorMountedTrigger() override;                                 // [0] 0x18155AAEC
    RTTR_ENABLE(C_ActorMountedTriggerBase)                             // [5..7], vtable 0x183B8F828
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                   // [27] 0x1829A8C84
    E_ActorMountState::Type unk_47() override;                         // [47] 0x181A74A40 returns value 2
    void unk_48() override;                                           // [48] 0x1806190FC
    void unk_49() override;                                           // [49] 0x180619868

    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_horse;                              // +0x188 RTTR "Horse"
    wh::rpgmodule::I_Soul* m_mountedHorse;                            // +0x1C8 borrowed active horse
};

static_assert(offsetof(C_ActorMountedTrigger, m_horse) == 0x188,
              "C_ActorMountedTrigger::m_horse offset mismatch");
static_assert(offsetof(C_ActorMountedTrigger, m_mountedHorse) == 0x1C8,
              "C_ActorMountedTrigger::m_mountedHorse offset mismatch");
static_assert(sizeof(C_ActorMountedTrigger) == 0x1D0,
              "C_ActorMountedTrigger size mismatch");

} // namespace wh::entitymodule
