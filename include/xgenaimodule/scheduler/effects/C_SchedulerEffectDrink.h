#pragma once
#include <cstddef>
#include <cstdint>
#include "../C_SchedulerEffectBase.h"

namespace wh::xgenaimodule::scheduler::effects {

class C_SchedulerEffectDrink : public C_SchedulerEffectBase {
public:
    ~C_SchedulerEffectDrink() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    void unk_04() override;
    RTTR_ENABLE(C_SchedulerEffectBase)
    std::uint8_t m_unknown10[8];                          // +0x10
};

static_assert(sizeof(C_SchedulerEffectDrink) == 0x18,
              "C_SchedulerEffectDrink size mismatch");

}  // namespace wh::xgenaimodule::scheduler::effects
