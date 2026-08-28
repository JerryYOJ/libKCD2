#pragma once

#include <cstddef>
#include <cstdint>

namespace wh::xgenaimodule::scheduler {

struct S_SchedulerLinkParameters {
    std::uint16_t m_timeOfDayStart;                                          // +0x00 RTTR "TimeOfDayStart"
    std::uint8_t m_unknown02[0x10];                                          // +0x02 duplicate "RequireFastForward" shorts
    std::uint16_t m_timeVariation;                                           // +0x12 RTTR "TimeVariation"
    std::uint8_t m_unknown14[0x14];                                          // +0x14
};

static_assert(offsetof(S_SchedulerLinkParameters, m_timeOfDayStart) == 0x00,
              "S_SchedulerLinkParameters::m_timeOfDayStart offset mismatch");
static_assert(offsetof(S_SchedulerLinkParameters, m_timeVariation) == 0x12,
              "S_SchedulerLinkParameters::m_timeVariation offset mismatch");
static_assert(sizeof(S_SchedulerLinkParameters) == 0x28,
              "S_SchedulerLinkParameters size mismatch");

} // namespace wh::xgenaimodule::scheduler
