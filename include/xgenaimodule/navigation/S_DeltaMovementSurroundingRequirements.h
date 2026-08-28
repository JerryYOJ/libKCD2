#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

namespace wh::xgenaimodule::navigation {

struct S_DeltaMovementSurroundingRequirements {
    int m_logicalSpeedId;                                   // +0x00 RTTR "LogicalSpeedId"
    std::uint8_t _pad04[4];                                 // +0x04
    std::vector<float> m_requiredDistancesSq;               // +0x08 accessor backing "RequiredDistancesSQ"
};

static_assert(offsetof(S_DeltaMovementSurroundingRequirements, m_logicalSpeedId) == 0x00,
              "S_DeltaMovementSurroundingRequirements::m_logicalSpeedId offset mismatch");
static_assert(offsetof(S_DeltaMovementSurroundingRequirements, m_requiredDistancesSq) == 0x08,
              "S_DeltaMovementSurroundingRequirements::m_requiredDistancesSq offset mismatch");
static_assert(sizeof(S_DeltaMovementSurroundingRequirements) == 0x20,
              "S_DeltaMovementSurroundingRequirements size mismatch");

}  // namespace wh::xgenaimodule::navigation
