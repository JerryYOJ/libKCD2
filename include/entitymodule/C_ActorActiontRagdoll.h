#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ActorAction.h"
#include "I_ActorAction.h"

namespace wh::entitymodule {

using C_ActorActiontRagdollBase =
    C_ActorAction<I_ActorAction, wh::framework::C_Action<I_ActorAction>>;

class C_ActorActiontRagdoll : public C_ActorActiontRagdollBase {
public:
    explicit C_ActorActiontRagdoll(C_ActionActor& actor);                  // 0x1812C09E8
    ~C_ActorActiontRagdoll() override;                                     // [0] 0x1812C0684
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x18137FD50
    std::int32_t GetActionTypeId() const override;                         // [14] 0x181A74260
    RTTR_ENABLE(C_ActorActiontRagdollBase)                                 // [23..25], vtable 0x183B52330
    void GetTagRange(void* output) override;                               // [31] 0x1817C2C38
    bool OnStart() override;                                               // [38] 0x180E79C68
    void OnStop() override;                                                // [39] 0x180AA13A8

    bool m_flag68;                                                         // +0x68 written by OnStart
    std::uint8_t m_padding69[3];                                           // +0x69
    std::uint32_t m_unknown6C;                                             // +0x6C initialized 0, read by OnStop
    std::uint32_t m_actorValue;                                            // +0x70 refreshed from the actor on start/callback
    std::uint8_t m_padding74[4];                                           // +0x74
};

static_assert(offsetof(C_ActorActiontRagdoll, m_flag68) == 0x68,
              "C_ActorActiontRagdoll::m_flag68 offset mismatch");
static_assert(offsetof(C_ActorActiontRagdoll, m_unknown6C) == 0x6C,
              "C_ActorActiontRagdoll::m_unknown6C offset mismatch");
static_assert(offsetof(C_ActorActiontRagdoll, m_actorValue) == 0x70,
              "C_ActorActiontRagdoll::m_actorValue offset mismatch");
static_assert(sizeof(C_ActorActiontRagdoll) == 0x78,
              "C_ActorActiontRagdoll size mismatch");

} // namespace wh::entitymodule
