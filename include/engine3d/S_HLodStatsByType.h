#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::engine3d {

class S_HLodStatsByType {
public:
    RTTR_ENABLE()                                           // [0..2]

    std::array<int, 7> m_stateCount;                        // +0x08 RTTR "StateCount"
    int m_streamedInInstanceCount;                          // +0x24 RTTR "StreamedInInstanceCount"
    int m_visibleProxyMeshMemoryUsage;                      // +0x28 RTTR "VisibleProxyMeshMemoryUsage"
    std::uint8_t m_unknown2C[4];                            // +0x2C unreflected
    int m_instStreamDataSizeInProgress;                     // +0x30 RTTR "InstStreamDataSizeInProgress"
    std::uint8_t m_unknown34[4];                            // +0x34 unreflected
};

static_assert(offsetof(S_HLodStatsByType, m_stateCount) == 0x08,
              "S_HLodStatsByType::m_stateCount offset mismatch");
static_assert(offsetof(S_HLodStatsByType, m_streamedInInstanceCount) == 0x24,
              "S_HLodStatsByType::m_streamedInInstanceCount offset mismatch");
static_assert(offsetof(S_HLodStatsByType, m_visibleProxyMeshMemoryUsage) == 0x28,
              "S_HLodStatsByType::m_visibleProxyMeshMemoryUsage offset mismatch");
static_assert(offsetof(S_HLodStatsByType, m_instStreamDataSizeInProgress) == 0x30,
              "S_HLodStatsByType::m_instStreamDataSizeInProgress offset mismatch");
static_assert(sizeof(S_HLodStatsByType) == 0x38,
              "S_HLodStatsByType size mismatch");

}  // namespace wh::engine3d
