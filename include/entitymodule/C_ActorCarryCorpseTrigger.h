#pragma once

#include <cstddef>

#include "../conceptmodule/C_TypedPortRef.h"
#include "C_ActorStateTrigger.h"

namespace wh::entitymodule {

using C_ActorCarryCorpseTriggerBase = C_ActorStateTrigger<E_ActorState::Type>;

class C_ActorCarryCorpseTrigger : public C_ActorCarryCorpseTriggerBase {
public:
    C_ActorCarryCorpseTrigger();                                      // 0x1810D5638
    ~C_ActorCarryCorpseTrigger() override;                            // [0] 0x181546558
    RTTR_ENABLE(C_ActorCarryCorpseTriggerBase)                        // [5..7], vtable 0x183B05C68
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                  // [27] 0x1829A8944
    E_ActorState::Type unk_47() override;                             // [47] 0x181A86DC0 returns carryCorpse
    void unk_48() override;                                          // [48] 0x1829AA074
    void unk_49() override;                                          // [49] 0x1829AA0A8

    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_corpse;                            // +0x188 RTTR "Corpse"
    wh::rpgmodule::I_Soul* m_carriedCorpse;                          // +0x1C8 borrowed active corpse
};

static_assert(offsetof(C_ActorCarryCorpseTrigger, m_corpse) == 0x188,
              "C_ActorCarryCorpseTrigger::m_corpse offset mismatch");
static_assert(offsetof(C_ActorCarryCorpseTrigger, m_carriedCorpse) == 0x1C8,
              "C_ActorCarryCorpseTrigger::m_carriedCorpse offset mismatch");
static_assert(sizeof(C_ActorCarryCorpseTrigger) == 0x1D0,
              "C_ActorCarryCorpseTrigger size mismatch");

} // namespace wh::entitymodule
