#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/primitives.h"
#include "../CryEngine/CryCommon/physinterface.h"
#include "../CryEngine/CryCommon/smartptr.h"

namespace wh::combatmodule {

struct S_SpatialGridResult {
    std::uint32_t m_entityId;          // +0x00
    Matrix33      m_obbBasis;          // +0x04, query space
    Vec3          m_obbSize;           // +0x28, half-extents
    Vec3          m_reserved34;        // +0x34, producer-zeroed
    Vec3          m_obbCenter;         // +0x40, query space
    Vec3          m_partOrigin;        // +0x4C, query space
    Matrix33      m_partBasis;         // +0x58, query space
    float         m_partScale;         // +0x7C
    std::int32_t  m_foreignId;         // +0x80
    bool          m_collisionClassSkip;// +0x84, AND.type bit 0x40000
    std::uint8_t  _pad85[3];           // +0x85
    _smart_ptr<IGeometry> m_pGeom;     // +0x88, owned
};
static_assert(sizeof(S_SpatialGridResult) == 0x90);
static_assert(offsetof(S_SpatialGridResult, m_entityId) == 0x00);
static_assert(offsetof(S_SpatialGridResult, m_obbBasis) == 0x04);
static_assert(offsetof(S_SpatialGridResult, m_obbSize) == 0x28);
static_assert(offsetof(S_SpatialGridResult, m_obbCenter) == 0x40);
static_assert(offsetof(S_SpatialGridResult, m_partBasis) == 0x58);
static_assert(offsetof(S_SpatialGridResult, m_partScale) == 0x7C);
static_assert(offsetof(S_SpatialGridResult, m_foreignId) == 0x80);
static_assert(offsetof(S_SpatialGridResult, m_pGeom) == 0x88);

}  // namespace wh::combatmodule
