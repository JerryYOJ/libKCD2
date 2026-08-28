#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "S_StatWrapper.h"

namespace wh::rpgmodule {

class C_StatisticTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    C_StatisticTrigger();
    ~C_StatisticTrigger() override;                               // [0]
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                               // [27]
    void OnEffectActivate() override;                             // [43]
    void OnEffectDeactivate() override;                           // [44]

    wh::conceptmodule::C_TypedPortRef<double> m_threshold;        // +0xB0
    wh::conceptmodule::C_TypedPortRef<S_StatWrapper> m_statistic; // +0xF0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onThresholdPassed;        // +0x130
    double m_resolvedThreshold;                                  // +0x170
    CryStringT<char> m_resolvedStatistic;                         // +0x178
};

static_assert(sizeof(C_StatisticTrigger) == 0x180,
              "C_StatisticTrigger size mismatch");
static_assert(offsetof(C_StatisticTrigger, m_threshold) == 0xB0,
              "C_StatisticTrigger threshold offset mismatch");
static_assert(offsetof(C_StatisticTrigger, m_onThresholdPassed) == 0x130,
              "C_StatisticTrigger output offset mismatch");
static_assert(offsetof(C_StatisticTrigger, m_resolvedThreshold) == 0x170,
              "C_StatisticTrigger resolved threshold offset mismatch");

} // namespace wh::rpgmodule
