#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_StateBase.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../framework/E_TimeType.h"
#include "../framework/S_TimeSpan.h"
#include "../framework/T_TimeoutTimer.h"
#include "E_TimerState.h"

namespace wh::rpgmodule {

struct T_GameWorldTimePolicy;

class C_Timer
    : public wh::conceptmodule::C_StateBase<E_TimerState::Type> {
public:
    C_Timer();
    ~C_Timer() override;                                        // [0]
    RTTR_ENABLE(wh::conceptmodule::C_StateBase<E_TimerState::Type>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                              // [27]
    void OnStateChanged(
        const E_TimerState::Type& oldValue,
        const E_TimerState::Type& newValue,
        bool changed) override;                                  // [42]
    bool IsAtDefaultValue() override;                            // [43]

    std::int64_t GetRemainingTime() const;                       // 0x182C48E38

    wh::conceptmodule::C_TypedPortRef<E_TimerState::Type> m_state; // +0x50
    wh::conceptmodule::C_TypedPortRef<
        wh::framework::S_TimeSpan> m_duration;                   // +0x90
    wh::conceptmodule::C_TypedPortRef<
        wh::framework::E_TimeType::Type> m_timeType;             // +0xD0
    bool m_listener0Registered;                                 // +0x110
    bool m_listener1Registered;                                 // +0x111
    std::uint8_t m_padding112[6];                              // +0x112
    wh::framework::T_TimeoutTimer<
        T_GameWorldTimePolicy> m_timeout;                        // +0x118
};

static_assert(sizeof(C_Timer) == 0x140,
              "C_Timer size mismatch");
static_assert(offsetof(C_Timer, m_state) == 0x50,
              "C_Timer state offset mismatch");
static_assert(offsetof(C_Timer, m_duration) == 0x90,
              "C_Timer duration offset mismatch");
static_assert(offsetof(C_Timer, m_timeType) == 0xD0,
              "C_Timer time-type offset mismatch");
static_assert(offsetof(C_Timer, m_timeout) == 0x118,
              "C_Timer timeout offset mismatch");

} // namespace wh::rpgmodule
