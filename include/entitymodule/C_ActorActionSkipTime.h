#pragma once

#include <cstddef>
#include <cstdint>

#include "../playermodule/E_SkipTime.h"
#include "C_ActorAction.h"
#include "I_ActorAction.h"

namespace wh::entitymodule {

using C_ActorActionSkipTimeBase =
    C_ActorAction<I_ActorAction, wh::framework::C_Action<I_ActorAction>>;

class C_ActorActionSkipTime : public C_ActorActionSkipTimeBase {
public:
    C_ActorActionSkipTime(C_ActionActor& actor,
                          wh::playermodule::E_SkipTime::Value skipTime);  // 0x1812C02B0
    ~C_ActorActionSkipTime() override;                                  // [0] 0x181444998
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x181380128
    std::int32_t GetActionTypeId() const override;                       // [14] 0x181A7F5D0
    RTTR_ENABLE(C_ActorActionSkipTimeBase)                               // [23..25], vtable 0x183B51998
    void GetTagRange(void* output) override;                             // [31] 0x1819CB46C
    bool OnStart() override;                                             // [38] 0x180F48C4C
    void OnStop() override;                                              // [39] 0x1819DBF4C
    std::int64_t OnTick() override;                                     // [41] 0x180F48B14

    wh::playermodule::E_SkipTime::Value m_skipTime;                      // +0x68
    bool m_runtimeFlag;                                                  // +0x6C
    std::uint8_t m_padding6D[3];                                        // +0x6D
};

static_assert(offsetof(C_ActorActionSkipTime, m_skipTime) == 0x68,
              "C_ActorActionSkipTime::m_skipTime offset mismatch");
static_assert(offsetof(C_ActorActionSkipTime, m_runtimeFlag) == 0x6C,
              "C_ActorActionSkipTime::m_runtimeFlag offset mismatch");
static_assert(sizeof(C_ActorActionSkipTime) == 0x70,
              "C_ActorActionSkipTime size mismatch");

} // namespace wh::entitymodule
