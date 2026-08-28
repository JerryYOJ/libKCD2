#pragma once
#include <cstddef>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "../framework/S_TimeOfDay.h"
#include "../framework/S_TimeSpan.h"

namespace wh::environmentmodule {

struct S_WeatherProfileData {
    struct S_Condition {
        float m_min;                                      // +0x00 RTTR "Min"
        float m_max;                                      // +0x04 RTTR "Max"
    };
    struct S_TimeOfDayInterval {
        wh::framework::S_TimeOfDay m_from;                // +0x00 RTTR "From"
        wh::framework::S_TimeOfDay m_to;                  // +0x08 RTTR "To"
    };

    CryStringT<char> m_name;                              // +0x00
    wh::framework::S_TimeSpan m_delayMin;                 // +0x08 RTTR "DelayMin"
    wh::framework::S_TimeSpan m_delayMax;                 // +0x10 RTTR "DelayMax"
    S_Condition m_temperature;                            // +0x18 RTTR "Temperature"
    S_Condition m_rainIntensity;                          // +0x20 RTTR "RainIntensity"
    S_Condition m_windVelocity;                           // +0x28 RTTR "WindVelocity"
    std::vector<S_TimeOfDayInterval> m_timeOfDayIntervals; // +0x30 RTTR "TimeOfDayIntervals"
};

static_assert(sizeof(S_WeatherProfileData::S_Condition) == 0x08,
              "S_WeatherProfileData::S_Condition size mismatch");
static_assert(sizeof(S_WeatherProfileData::S_TimeOfDayInterval) == 0x10,
              "S_WeatherProfileData::S_TimeOfDayInterval size mismatch");
static_assert(offsetof(S_WeatherProfileData, m_timeOfDayIntervals) == 0x30,
              "S_WeatherProfileData::m_timeOfDayIntervals offset mismatch");
static_assert(sizeof(S_WeatherProfileData) == 0x48,
              "S_WeatherProfileData size mismatch");

}  // namespace wh::environmentmodule
