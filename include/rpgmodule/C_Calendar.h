#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/ITimeOfDayUpdateCallbackBinary.h"
#include "../framework/C_Signal.h"
#include "rttr/rttr_enable.h"

namespace wh::rpgmodule {

class C_Calendar : public ITimeOfDayUpdateCallback {
public:
    C_Calendar();
    ~C_Calendar() override;                                    // [0]
    void BeginUpdate() override;                               // [1]
    bool GetCustomValue(
        std::int32_t paramId,
        int dimension,
        float* values,
        float& blendWeight) override;                          // [2]
    void EndUpdate() override;                                 // [3]
    virtual bool Update(float frameTime);                      // [4]
    RTTR_ENABLE() // [5..7]

    wh::shared::C_Signal<std::int64_t> m_timeSignal0;          // +0x08
    wh::shared::C_Signal<std::int64_t> m_timeSignal1;          // +0x18
    wh::shared::C_Signal<std::int64_t> m_timeSignal2;          // +0x28
    wh::shared::C_Signal<> m_dayChanged;                       // +0x38
    std::int64_t m_time48;                                     // +0x48
    std::int64_t m_time50;                                     // +0x50
    std::int64_t m_gameplayTime;                               // +0x58
    float m_timeScale60;                                       // +0x60
    float m_timeScale64;                                       // +0x64
    std::uint8_t m_runtimeTimeControls[0x20];                  // +0x68
    float m_fraction88;                                        // +0x88
    float m_fraction8C;                                        // +0x8C
    float m_fraction90;                                        // +0x90
    bool m_state94;                                            // +0x94
    std::uint8_t m_padding95[3];                              // +0x95
    float m_value98;                                           // +0x98
    std::uint8_t m_padding9C[4];                              // +0x9C
};

static_assert(sizeof(C_Calendar) == 0xA0,
              "C_Calendar size mismatch");
static_assert(offsetof(C_Calendar, m_gameplayTime) == 0x58,
              "C_Calendar gameplay time offset mismatch");
static_assert(offsetof(C_Calendar, m_runtimeTimeControls) == 0x68,
              "C_Calendar time-control offset mismatch");

} // namespace wh::rpgmodule
