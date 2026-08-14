#pragma once

#include "../../framework/WUID.h"

namespace wh::xgenaimodule::navigation {

class C_ReplanMoveArea;

struct S_ReplanMoveAreaRegistryEntry {
    framework::WUID wuid;
    C_ReplanMoveArea* area;
    std::int32_t navigationId;
    std::uint32_t _padding;
};
static_assert(sizeof(S_ReplanMoveAreaRegistryEntry) == 0x18,
              "S_ReplanMoveAreaRegistryEntry must be 0x18");

}  // namespace wh::xgenaimodule::navigation
