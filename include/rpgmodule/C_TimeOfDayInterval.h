#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../framework/S_TimeOfDay.h"

namespace wh::rpgmodule {

class C_TimeOfDayInterval
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    C_TimeOfDayInterval();
    ~C_TimeOfDayInterval() override;                            // [0]
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                              // [27]
    void OnEffectActivate() override;                           // [43]
    void OnEffectDeactivate() override;                         // [44]

    wh::conceptmodule::C_TypedPortRef<
        wh::framework::S_TimeOfDay> m_timeOfDayStart;            // +0xB0
    wh::conceptmodule::C_TypedPortRef<
        wh::framework::S_TimeOfDay> m_timeOfDayEnd;              // +0xF0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onIntervalStarted;       // +0x130
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onIntervalEnded;         // +0x170
    std::uint32_t m_intervalPhase;                              // +0x1B0
    std::uint8_t m_padding1B4[4];                              // +0x1B4
    std::int64_t m_intervalStartTime;                           // +0x1B8
    std::int64_t m_intervalEndTime;                             // +0x1C0
};

static_assert(sizeof(C_TimeOfDayInterval) == 0x1C8,
              "C_TimeOfDayInterval size mismatch");
static_assert(offsetof(C_TimeOfDayInterval, m_timeOfDayStart) == 0xB0,
              "C_TimeOfDayInterval start offset mismatch");
static_assert(offsetof(C_TimeOfDayInterval, m_onIntervalStarted) == 0x130,
              "C_TimeOfDayInterval started output offset mismatch");
static_assert(offsetof(C_TimeOfDayInterval, m_intervalPhase) == 0x1B0,
              "C_TimeOfDayInterval phase offset mismatch");
static_assert(offsetof(C_TimeOfDayInterval, m_intervalStartTime) == 0x1B8,
              "C_TimeOfDayInterval start time offset mismatch");

} // namespace wh::rpgmodule
