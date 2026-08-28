#pragma once

#include <cstddef>
#include <cstdint>

#include "S_SchedulerLinkParameters.h"

namespace wh::xgenaimodule::scheduler {

struct S_SchedulerLink {
    std::uint64_t m_targetGuid;                                              // +0x00 accessor "TargetGuid"
    std::uint64_t m_positioningDelegate;                                     // +0x08 RTTR "PositioningDelegate"
    S_SchedulerLinkParameters m_parameters;                                  // +0x10 RTTR "Parameters"
};

static_assert(offsetof(S_SchedulerLink, m_positioningDelegate) == 0x08,
              "S_SchedulerLink::m_positioningDelegate offset mismatch");
static_assert(offsetof(S_SchedulerLink, m_parameters) == 0x10,
              "S_SchedulerLink::m_parameters offset mismatch");
static_assert(sizeof(S_SchedulerLink) == 0x38,
              "S_SchedulerLink size mismatch");

} // namespace wh::xgenaimodule::scheduler
