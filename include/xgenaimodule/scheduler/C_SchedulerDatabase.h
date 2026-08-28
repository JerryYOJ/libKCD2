#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../../databasemodule/C_ObjectDatabaseBase.h"
#include "../../databasemodule/C_ObjectTreeDatabase.h"
#include "C_SmartHub.h"
#include "S_SchedulerLink.h"

namespace wh::xgenaimodule::scheduler {

using C_SchedulerDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabase<C_SmartHub, std::vector>;

class C_SchedulerDatabase : public C_SchedulerDatabaseBase {
public:
    ~C_SchedulerDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)                    // [18..20], vtable 0x1840082E0

    std::vector<S_SchedulerLink> m_links;                                    // +0x78 RTTR "Links"
    std::uint8_t m_unknown90[0xB0];                                          // +0x90
};

static_assert(offsetof(C_SchedulerDatabase, m_links) == 0x78,
              "C_SchedulerDatabase::m_links offset mismatch");
static_assert(sizeof(C_SchedulerDatabase) == 0x140,
              "C_SchedulerDatabase size mismatch");

} // namespace wh::xgenaimodule::scheduler
