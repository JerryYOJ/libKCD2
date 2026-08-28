#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

namespace wh::xgenaimodule::navigation {

struct S_DeltaMovementSurroundingDef {
    std::vector<float> m_sectorEndAngles;                   // +0x00 accessor backing "SectorEndAnglesDeg"
    float m_distance;                                       // +0x18 RTTR "Distance"
    std::uint8_t _pad1C[4];                                 // +0x1C
};

static_assert(offsetof(S_DeltaMovementSurroundingDef, m_sectorEndAngles) == 0x00,
              "S_DeltaMovementSurroundingDef::m_sectorEndAngles offset mismatch");
static_assert(offsetof(S_DeltaMovementSurroundingDef, m_distance) == 0x18,
              "S_DeltaMovementSurroundingDef::m_distance offset mismatch");
static_assert(sizeof(S_DeltaMovementSurroundingDef) == 0x20,
              "S_DeltaMovementSurroundingDef size mismatch");

}  // namespace wh::xgenaimodule::navigation
