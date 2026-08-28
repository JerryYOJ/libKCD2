#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_StateBase.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../framework/S_TimeOfDay.h"
#include "E_TimeOfDayState.h"

namespace wh::rpgmodule {

class C_TimeOfDayWatch
    : public wh::conceptmodule::C_StateBase<E_TimeOfDayState::Type> {
public:
    C_TimeOfDayWatch();
    ~C_TimeOfDayWatch() override;                               // [0]
    RTTR_ENABLE(wh::conceptmodule::C_StateBase<E_TimeOfDayState::Type>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                              // [27]
    void OnStateChanged(
        const E_TimeOfDayState::Type& oldValue,
        const E_TimeOfDayState::Type& newValue,
        bool changed) override;                                  // [42]
    bool IsAtDefaultValue() override;                            // [43]

    wh::conceptmodule::C_TypedPortRef<
        E_TimeOfDayState::Type> m_state;                         // +0x50
    wh::conceptmodule::C_TypedPortRef<
        wh::framework::S_TimeOfDay> m_timeOfDayStart;            // +0x90
    wh::conceptmodule::C_TypedPortRef<
        wh::framework::S_TimeOfDay> m_timeOfDayEnd;              // +0xD0
    wh::conceptmodule::C_TypedPortRef<std::int32_t> m_daysToStart; // +0x110
    wh::conceptmodule::C_TypedPortRef<
        std::int32_t> m_daysToInterrupt;                         // +0x150
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onTimeOfDay;             // +0x190
    bool m_listenerRegistered;                                  // +0x1D0
    std::uint8_t m_padding1D1[7];                              // +0x1D1
    std::int64_t m_intervalStartTime;                            // +0x1D8
    std::int64_t m_intervalEndTime;                              // +0x1E0
    std::int32_t m_remainingDaysToInterrupt;                    // +0x1E8
    std::uint8_t m_padding1EC[4];                              // +0x1EC
};

static_assert(sizeof(C_TimeOfDayWatch) == 0x1F0,
              "C_TimeOfDayWatch size mismatch");
static_assert(offsetof(C_TimeOfDayWatch, m_state) == 0x50,
              "C_TimeOfDayWatch state offset mismatch");
static_assert(offsetof(C_TimeOfDayWatch, m_timeOfDayStart) == 0x90,
              "C_TimeOfDayWatch start port offset mismatch");
static_assert(offsetof(C_TimeOfDayWatch, m_onTimeOfDay) == 0x190,
              "C_TimeOfDayWatch trigger offset mismatch");
static_assert(offsetof(C_TimeOfDayWatch, m_intervalStartTime) == 0x1D8,
              "C_TimeOfDayWatch interval start offset mismatch");
static_assert(offsetof(C_TimeOfDayWatch, m_remainingDaysToInterrupt) == 0x1E8,
              "C_TimeOfDayWatch remaining-days offset mismatch");

} // namespace wh::rpgmodule
