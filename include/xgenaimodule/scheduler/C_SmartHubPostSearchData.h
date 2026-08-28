#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "C_SchedulerEffectBase.h"

namespace wh::xgenaimodule::scheduler {

class C_SmartHubPostSearchData {
public:
    std::uint8_t m_unknown00[0x18];                                          // +0x00 accessor ElementInitializers
    std::vector<C_SchedulerEffectBase*> m_schedulerEffect;                   // +0x18 RTTR "SchedulerEffect"
    std::uint8_t m_unknown30[0x18];                                          // +0x30
};

static_assert(offsetof(C_SmartHubPostSearchData, m_schedulerEffect) == 0x18,
              "C_SmartHubPostSearchData::m_schedulerEffect offset mismatch");
static_assert(sizeof(C_SmartHubPostSearchData) == 0x48,
              "C_SmartHubPostSearchData size mismatch");

} // namespace wh::xgenaimodule::scheduler
