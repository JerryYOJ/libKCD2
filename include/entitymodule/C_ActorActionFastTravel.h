#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ActorAction.h"
#include "I_ActorAction.h"

namespace wh::entitymodule {

using C_ActorActionFastTravelBase =
    C_ActorAction<I_ActorAction, wh::framework::C_Action<I_ActorAction>>;

class C_ActorActionFastTravel : public C_ActorActionFastTravelBase {
public:
    explicit C_ActorActionFastTravel(C_ActionActor& actor);              // 0x182893BC4
    ~C_ActorActionFastTravel() override;                                 // [0] 0x1828951B0
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x182895D64
    std::int32_t GetActionTypeId() const override;                       // [14] 0x181A82B80
    RTTR_ENABLE(C_ActorActionFastTravelBase)                             // [23..25], vtable 0x184709900
    void GetTagRange(void* output) override;                             // [31] 0x18289A4B8
    bool OnStart() override;                                             // [38] 0x1828970F0
    void OnStop() override;                                              // [39] 0x182898D1C
    std::int64_t OnTick() override;                                     // [41] 0x1828A0E48

    bool m_runtimeFlag;                                                  // +0x68
    std::uint8_t m_padding69[7];                                        // +0x69
};

static_assert(offsetof(C_ActorActionFastTravel, m_runtimeFlag) == 0x68,
              "C_ActorActionFastTravel::m_runtimeFlag offset mismatch");
static_assert(sizeof(C_ActorActionFastTravel) == 0x70,
              "C_ActorActionFastTravel size mismatch");

} // namespace wh::entitymodule
