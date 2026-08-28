#pragma once

#include <cstddef>
#include <cstdint>

namespace wh::xgenaimodule::scheduler {

struct S_SchedulerAlias {
    CryStringT<char> m_name;                                                 // +0x00 RTTR "Name"
    std::uint8_t m_unknown08[0x28];                                          // +0x08 accessor Parameters
};

static_assert(offsetof(S_SchedulerAlias, m_name) == 0x00,
              "S_SchedulerAlias::m_name offset mismatch");
static_assert(sizeof(S_SchedulerAlias) == 0x30,
              "S_SchedulerAlias size mismatch");

} // namespace wh::xgenaimodule::scheduler
