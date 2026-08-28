#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "S_DeltaMovementSurroundingRequirements.h"

namespace wh::xgenaimodule::navigation {

struct S_DeltaMovementPartialSurroundingRequirements {
    std::uint64_t m_coveredSectorCount;                     // +0x00 RTTR "CoveredSectorCount"
    int m_slowDownThresholdLogicalSpeedId;                  // +0x08 RTTR "SlowDownThresholdLogicalSpeedId"
    std::uint8_t _pad0C[4];                                 // +0x0C
    std::vector<S_DeltaMovementSurroundingRequirements> m_speedRequirements; // +0x10 RTTR "SpeedRequirements"
};

static_assert(offsetof(S_DeltaMovementPartialSurroundingRequirements, m_coveredSectorCount) == 0x00,
              "S_DeltaMovementPartialSurroundingRequirements::m_coveredSectorCount offset mismatch");
static_assert(offsetof(S_DeltaMovementPartialSurroundingRequirements, m_speedRequirements) == 0x10,
              "S_DeltaMovementPartialSurroundingRequirements::m_speedRequirements offset mismatch");
static_assert(sizeof(S_DeltaMovementPartialSurroundingRequirements) == 0x28,
              "S_DeltaMovementPartialSurroundingRequirements size mismatch");

}  // namespace wh::xgenaimodule::navigation
