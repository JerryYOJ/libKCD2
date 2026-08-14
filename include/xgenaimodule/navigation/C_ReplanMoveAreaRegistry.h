#pragma once

#include <vector>
#include "S_ReplanMoveAreaRegistryEntry.h"

namespace wh::xgenaimodule::navigation {

// Descriptive name: the binary exposes this non-polymorphic registry but no source symbol.
class C_ReplanMoveAreaRegistry {
public:
    static C_ReplanMoveAreaRegistry* GetInstance();
    C_ReplanMoveArea* FindByWuid(const framework::WUID& wuid);

    std::uint8_t m_resourceHandle[0x10];
    std::vector<S_ReplanMoveAreaRegistryEntry> m_entries; // +0x10, sorted by WUID
    std::uint8_t m_allocatorState[0x18];                  // +0x28
};
static_assert(sizeof(C_ReplanMoveAreaRegistry) == 0x40,
              "C_ReplanMoveAreaRegistry must be 0x40");

}  // namespace wh::xgenaimodule::navigation
