#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ActorAction.h"
#include "I_ActorAction.h"

namespace wh::entitymodule {

using C_ActorActionTenseCircumstanceBase =
    C_ActorAction<I_ActorAction, wh::framework::C_Action<I_ActorAction>>;

class C_ActorActionTenseCircumstance
    : public C_ActorActionTenseCircumstanceBase {
public:
    explicit C_ActorActionTenseCircumstance(C_ActionActor& actor);       // 0x1812C0640
    ~C_ActorActionTenseCircumstance() override;                          // [0] 0x181444998
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x18137FE78
    bool _vf12() const override;                                         // [12] 0x180838AE0
    std::int32_t GetActionTypeId() const override;                       // [14] 0x181A82B90
    RTTR_ENABLE(C_ActorActionTenseCircumstanceBase)                      // [23..25], vtable 0x183B51D88
    void GetTagRange(void* output) override;                             // [31] 0x181978718
    bool OnStart() override;                                             // [38] 0x18041A6A0
    void OnStop() override;                                              // [39] 0x1803B6E80
};

static_assert(sizeof(C_ActorActionTenseCircumstance) == 0x68,
              "C_ActorActionTenseCircumstance size mismatch");

} // namespace wh::entitymodule
