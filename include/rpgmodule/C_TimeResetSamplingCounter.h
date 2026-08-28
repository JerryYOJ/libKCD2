#pragma once
#include "C_TimeSamplingCounter.h"

namespace wh::rpgmodule {

template <typename TPolicy>
class C_TimeResetSamplingCounter : public C_TimeSamplingCounter<TPolicy> {
public:
    explicit C_TimeResetSamplingCounter(S_Statistic const& statistic);
    ~C_TimeResetSamplingCounter() override;
    RTTR_ENABLE(C_TimeSamplingCounter<TPolicy>)              // [12..14]
    void unk_15() override;                                  // [15], reset-aware sample
    void unk_24() override;                                  // [24], clears callback-visible value
};

static_assert(sizeof(C_TimeResetSamplingCounter<T_GameTimePolicy>) == 0x80,
              "C_TimeResetSamplingCounter<T_GameTimePolicy> size mismatch");
static_assert(sizeof(C_TimeResetSamplingCounter<T_WorldTimePolicy>) == 0x80,
              "C_TimeResetSamplingCounter<T_WorldTimePolicy> size mismatch");

}  // namespace wh::rpgmodule
