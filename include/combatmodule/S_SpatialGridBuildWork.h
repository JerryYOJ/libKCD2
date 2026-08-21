#pragma once
#include <cstddef>
#include <cstdint>
#include "S_SpatialGridBuildPrim.h"
#include "S_SpatialGridNode.h"
#include "../framework/InplaceVector.h"

namespace wh::combatmodule {

struct S_SpatialGridBuildWork {
    S_SpatialGridNode* m_pNode; // +0x0000, borrowed
    wh::shared::InplaceVector<S_SpatialGridBuildPrim, 100> m_prims; // +0x0008
    std::uint8_t m_dissectionIndex; // +0x41D8
    std::uint8_t _pad41D9[7];       // +0x41D9
};
static_assert(sizeof(wh::shared::InplaceVector<S_SpatialGridBuildPrim, 100>) == 0x41D0);
static_assert(sizeof(S_SpatialGridBuildWork) == 0x41E0);
static_assert(offsetof(S_SpatialGridBuildWork, m_pNode) == 0x0000);
static_assert(offsetof(S_SpatialGridBuildWork, m_prims) == 0x0008);
static_assert(offsetof(S_SpatialGridBuildWork, m_dissectionIndex) == 0x41D8);

}  // namespace wh::combatmodule
