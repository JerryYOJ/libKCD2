#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Geo.h"
#include "../CryEngine/CryCommon/primitives.h"
#include "../CryEngine/CryCommon/physinterface.h"
#include "../CryEngine/CryCommon/smartptr.h"

namespace wh::combatmodule {

struct S_SpatialGridBuildPrim {
    Vec3     m_translation;       // +0x00
    Matrix33 m_basis;             // +0x0C
    float    m_scale;             // +0x30
    std::uint8_t _pad34[0x2C];    // +0x34, zeroed/no consumer
    _smart_ptr<IGeometry> m_pGeom;// +0x60, owned
    OBB      m_worldOBB;          // +0x68
    std::uint8_t _padA4[4];       // +0xA4
};
static_assert(sizeof(OBB) == 0x3C);
static_assert(sizeof(S_SpatialGridBuildPrim) == 0xA8);
static_assert(offsetof(S_SpatialGridBuildPrim, m_translation) == 0x00);
static_assert(offsetof(S_SpatialGridBuildPrim, m_basis) == 0x0C);
static_assert(offsetof(S_SpatialGridBuildPrim, m_scale) == 0x30);
static_assert(offsetof(S_SpatialGridBuildPrim, m_pGeom) == 0x60);
static_assert(offsetof(S_SpatialGridBuildPrim, m_worldOBB) == 0x68);

}  // namespace wh::combatmodule
