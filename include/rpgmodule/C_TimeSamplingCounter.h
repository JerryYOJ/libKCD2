#pragma once
#include "C_SamplingCounter.h"
#include "T_GameTimePolicy.h"
#include "T_WorldTimePolicy.h"

namespace wh::rpgmodule {

struct S_Statistic;

template <typename TPolicy>
class C_TimeSamplingCounter : public C_SamplingCounter {
public:
    explicit C_TimeSamplingCounter(S_Statistic const& statistic);
    ~C_TimeSamplingCounter() override;
    double unk_07() override;                                // [7], policy value in hours
    RTTR_ENABLE(C_SamplingCounter)                            // [12..14]
    void unk_15() override;                                  // [15]
    void unk_16() override;                                  // [16]
    void unk_17() override;                                  // [17]
    void unk_18() override;                                  // [18]
    void unk_23() override;                                  // [23]
    void unk_24() override;                                  // [24]

    double GetValue() const;                                 // 0x182138C98, RTTR getter -> [7]
    void Reset();                                            // 0x18213A0B4, RTTR method -> [19]
};

static_assert(sizeof(C_TimeSamplingCounter<T_GameTimePolicy>) == 0x80,
              "C_TimeSamplingCounter<T_GameTimePolicy> size mismatch");
static_assert(sizeof(C_TimeSamplingCounter<T_WorldTimePolicy>) == 0x80,
              "C_TimeSamplingCounter<T_WorldTimePolicy> size mismatch");

}  // namespace wh::rpgmodule
