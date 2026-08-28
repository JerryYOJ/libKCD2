#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ActorAction.h"
#include "I_ActorAction.h"

namespace wh::entitymodule {

using C_ActorActionCarriedBase =
    C_ActorAction<I_ActorAction, wh::framework::C_Action<I_ActorAction>>;

class C_ActorActionCarried : public C_ActorActionCarriedBase {
public:
    explicit C_ActorActionCarried(C_ActionActor& actor);                 // 0x1828784DC
    ~C_ActorActionCarried() override;                                    // [0] 0x18287882C
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x182879004
    void _vf9() override;                                                // [9] 0x18287C4C0
    std::int32_t GetActionTypeId() const override;                       // [14] 0x181A7F5C0
    RTTR_ENABLE(C_ActorActionCarriedBase)                                // [23..25], vtable 0x184700998
    void GetTagRange(void* output) override;                             // [31] 0x18287B1F4
    bool OnStart() override;                                             // [38] 0x18041A6A0
    void OnStop() override;                                              // [39] 0x1803B6E80
};

static_assert(sizeof(C_ActorActionCarried) == 0x68,
              "C_ActorActionCarried size mismatch");

} // namespace wh::entitymodule
