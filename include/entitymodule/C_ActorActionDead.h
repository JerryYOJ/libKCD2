#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ActorAction.h"
#include "I_ActorAction.h"
#include "I_DisableRagdollEffect.h"

namespace wh::entitymodule {

using C_ActorActionDeadBase =
    C_ActorAction<I_ActorAction, wh::framework::C_Action<I_ActorAction>>;

class C_ActorActionDead
    : public C_ActorActionDeadBase,
      public I_DisableRagdollEffect {
public:
    explicit C_ActorActionDead(C_ActionActor& actor);                      // 0x1812C0B74
    ~C_ActorActionDead() override;                                         // [0] 0x1812C0A34
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x18137FCB8
    std::int32_t GetActionTypeId() const override;                         // [14] 0x181A7D840
    RTTR_ENABLE(C_ActorActionDeadBase, I_DisableRagdollEffect)             // Primary [23..25], +0x68 [1..3]
    std::int32_t GetStaticTypeId() const override;                         // [26] 0x180F591C0
    void vfE8(void* event) override;                                       // [29] 0x1811BC950; reads event+0x08
    void GetTagRange(void* output) override;                               // [31] 0x18163FEC8
    bool OnStart() override;                                               // [38] 0x180E78768
    void OnStop() override;                                                // [39] 0x180E78668

    void DisableRagdollEffect() override;                                  // +0x68 [0] 0x1816D5430

    bool m_deadStateLatched;                                               // +0x70 set when OnStart observes the dead state
    bool m_disableRagdollEffect;                                           // +0x71 set through I_DisableRagdollEffect
    std::uint8_t m_padding72[6];                                           // +0x72
};

static_assert(offsetof(C_ActorActionDead, m_deadStateLatched) == 0x70,
              "C_ActorActionDead::m_deadStateLatched offset mismatch");
static_assert(offsetof(C_ActorActionDead, m_disableRagdollEffect) == 0x71,
              "C_ActorActionDead::m_disableRagdollEffect offset mismatch");
static_assert(sizeof(C_ActorActionDead) == 0x78,
              "C_ActorActionDead size mismatch");

} // namespace wh::entitymodule
