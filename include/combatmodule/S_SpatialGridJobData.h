#pragma once
#include <cstddef>
#include <cstdint>
#include "S_SpatialGridResult.h"
#include "../CryEngine/CryCommon/primitives.h"
#include "../framework/InplaceVector.h"

namespace wh::combatmodule {

struct S_SpatialGridJobData {
    primitives::box m_queryBox;       // +0x0000
    Matrix34        m_queryFrame;      // +0x0040
    Vec3            m_queryCenter;     // +0x0070
    float           m_halfExtent;      // +0x007C
    float           m_halfExtentSecondary; // +0x0080
    std::int32_t    m_shapeControl;    // +0x0084
    std::uint32_t   m_frameId;         // +0x0088
    std::uint32_t   _pad8C;            // +0x008C
    wh::shared::InplaceVector<S_SpatialGridResult, 30> m_results; // +0x0090
};
static_assert(sizeof(wh::shared::InplaceVector<S_SpatialGridResult, 30>) == 0x1110);
static_assert(sizeof(S_SpatialGridJobData) == 0x11A0);
static_assert(offsetof(S_SpatialGridJobData, m_queryBox) == 0x0000);
static_assert(offsetof(S_SpatialGridJobData, m_queryFrame) == 0x0040);
static_assert(offsetof(S_SpatialGridJobData, m_queryCenter) == 0x0070);
static_assert(offsetof(S_SpatialGridJobData, m_halfExtent) == 0x007C);
static_assert(offsetof(S_SpatialGridJobData, m_shapeControl) == 0x0084);
static_assert(offsetof(S_SpatialGridJobData, m_frameId) == 0x0088);
static_assert(offsetof(S_SpatialGridJobData, m_results) == 0x0090);

}  // namespace wh::combatmodule
