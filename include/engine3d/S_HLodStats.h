#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"
#include "S_HLodStatsByType.h"

namespace wh::engine3d {

class S_HLodStats {
public:
    RTTR_ENABLE()                                           // [0..2]

    std::array<int, 7> m_stateCount;                        // +0x08 RTTR "StateCount"
    std::uint8_t m_unknown24[4];                            // +0x24 unreflected
    std::array<S_HLodStatsByType, 6> m_byType;              // +0x28 RTTR "ByType"
    int m_instStreamTasksInProgress;                        // +0x178 RTTR "InstStreamTasksInProgress"
    int m_instStreamDataSizeInProgress;                     // +0x17C RTTR "InstStreamDataSizeInProgress"
};

static_assert(offsetof(S_HLodStats, m_stateCount) == 0x08,
              "S_HLodStats::m_stateCount offset mismatch");
static_assert(offsetof(S_HLodStats, m_byType) == 0x28,
              "S_HLodStats::m_byType offset mismatch");
static_assert(offsetof(S_HLodStats, m_instStreamTasksInProgress) == 0x178,
              "S_HLodStats::m_instStreamTasksInProgress offset mismatch");
static_assert(offsetof(S_HLodStats, m_instStreamDataSizeInProgress) == 0x17C,
              "S_HLodStats::m_instStreamDataSizeInProgress offset mismatch");
static_assert(sizeof(S_HLodStats) == 0x180,
              "S_HLodStats size mismatch");

}  // namespace wh::engine3d
