#pragma once

#include <cstddef>
#include <cstdint>

#include "../game/I_EntitySideEffectCallback.h"
#include "C_ActorAction.h"
#include "I_ActorAction.h"
#include "I_DisableRagdollEffect.h"

namespace wh::entitymodule {

using C_ActorActionUnconsciousBase =
    C_ActorAction<I_ActorAction, wh::framework::C_Action<I_ActorAction>>;

class C_ActorActionUnconscious
    : public C_ActorActionUnconsciousBase,
      public I_DisableRagdollEffect,
      public wh::game::I_EntitySideEffectCallback {
public:
    explicit C_ActorActionUnconscious(C_ActionActor& actor);               // 0x182893FE8
    ~C_ActorActionUnconscious() override;                                  // [0] 0x18289541C
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x182895D9C
    std::int32_t GetActionTypeId() const override;                         // [14] 0x181A7D850
    RTTR_ENABLE(C_ActorActionUnconsciousBase, I_DisableRagdollEffect)       // Primary [23..25], +0x68 [1..3]
    void GetTagRange(void* output) override;                               // [31] 0x18289A598
    bool OnStart() override;                                               // [38] 0x182898668
    void OnStop() override;                                                // [39] 0x1828994E4

    void DisableRagdollEffect() override;                                  // +0x68 [0] 0x181A82B00
    void OnEntitySideEffectAdded(
        std::uint8_t sideEffectId,
        wh::framework::WUID entityWuid) override;                          // +0x70 [0] 0x18289F44C
    void OnEntitySideEffectRemoved(
        std::uint8_t sideEffectId,
        wh::framework::WUID entityWuid) override;                          // +0x70 [1] 0x1803B6E80

    bool m_disableRagdollEffect;                                           // +0x78 set through I_DisableRagdollEffect
    std::uint8_t m_padding79[7];                                           // +0x79
};

static_assert(offsetof(C_ActorActionUnconscious, m_disableRagdollEffect) == 0x78,
              "C_ActorActionUnconscious::m_disableRagdollEffect offset mismatch");
static_assert(sizeof(C_ActorActionUnconscious) == 0x80,
              "C_ActorActionUnconscious size mismatch");

} // namespace wh::entitymodule
