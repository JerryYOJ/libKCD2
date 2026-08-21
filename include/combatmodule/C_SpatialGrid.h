#pragma once
#include <cstddef>
#include <cstdint>
#include <list>
#include <memory>
#include <vector>
#include "S_SpatialGridBuildWork.h"
#include "S_SpatialGridNode.h"
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../framework/C_CryJobWrap.h"

struct IPhysicalEntity;

namespace wh::combatmodule {

class C_SpatialGrid {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SpatialGrid;
    C_SpatialGrid();
    virtual ~C_SpatialGrid(); // [0], sole virtual slot

    Matrix34 m_activeWorldTM;  // +0x008
    Matrix34 m_stagingWorldTM; // +0x038
    Quat m_activeRotation;     // +0x068
    Quat m_stagingRotation;    // +0x078
    std::vector<IPhysicalEntity*> m_ignoredPhysicalEntities; // +0x088, borrowed
    float m_radius;            // +0x0A0
    Vec3 m_gridVector;         // +0x0A4
    std::int32_t m_dissectionDepth; // +0x0B0
    std::uint32_t _padB4;      // +0x0B4
    S_SpatialGridNode m_activeRootStorage; // +0x0B8
    S_SpatialGridNode* m_pActiveRoot;      // +0x0C8
    std::vector<std::uint8_t> m_dissectionPattern; // +0x0D0
    S_SpatialGridNode m_stagingRootStorage; // +0x0E8
    S_SpatialGridNode* m_pStagingRoot;      // +0x0F8
    bool m_isReady;             // +0x100
    std::uint8_t _pad101[7];    // +0x101
    std::list<S_SpatialGridBuildWork> m_buildWork; // +0x108, owned
    std::unique_ptr<wh::framework::C_CryJobWrap<C_SpatialGrid*, C_SpatialGrid*&>>
        m_pBuildJob; // +0x118, owned
};
static_assert(sizeof(C_SpatialGrid) == 0x120);
static_assert(offsetof(C_SpatialGrid, m_activeWorldTM) == 0x008);
static_assert(offsetof(C_SpatialGrid, m_stagingWorldTM) == 0x038);
static_assert(offsetof(C_SpatialGrid, m_ignoredPhysicalEntities) == 0x088);
static_assert(offsetof(C_SpatialGrid, m_radius) == 0x0A0);
static_assert(offsetof(C_SpatialGrid, m_activeRootStorage) == 0x0B8);
static_assert(offsetof(C_SpatialGrid, m_pActiveRoot) == 0x0C8);
static_assert(offsetof(C_SpatialGrid, m_dissectionPattern) == 0x0D0);
static_assert(offsetof(C_SpatialGrid, m_stagingRootStorage) == 0x0E8);
static_assert(offsetof(C_SpatialGrid, m_pStagingRoot) == 0x0F8);
static_assert(offsetof(C_SpatialGrid, m_isReady) == 0x100);
static_assert(offsetof(C_SpatialGrid, m_buildWork) == 0x108);
static_assert(offsetof(C_SpatialGrid, m_pBuildJob) == 0x118);

}  // namespace wh::combatmodule
