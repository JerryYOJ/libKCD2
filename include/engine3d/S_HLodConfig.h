#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../rttr/rttr_enable.h"

namespace wh::engine3d {

class S_HLodConfig {
public:
    RTTR_ENABLE()                                           // [0..2]

    float m_clusterSwitchingDistanceMin;                    // +0x08 RTTR "ClusterSwitchingDistanceMin"
    float m_clusterSwitchingDistanceMultiplier;             // +0x0C RTTR "ClusterSwitchingDistanceMultiplier"
    float m_clusterSwitchingDistanceExponent;               // +0x10 RTTR "ClusterSwitchingDistanceExponent"
    float m_interiorSwitchingDistance;                       // +0x14 RTTR "InteriorSwitchingDistance"
    std::vector<float> m_vegetationSwitchingDistances;       // +0x18 accessor backing
    int m_switchingDistanceIn2D;                             // +0x30 RTTR "SwitchingDistanceIn2D"
    float m_hysteresisDistance;                              // +0x34 RTTR "HysteresisDistance"
    float m_significantObjectRatio;                          // +0x38 RTTR "SignificantObjectRatio"
    int m_viewDistRatioOverride;                             // +0x3C RTTR "ViewDistRatioOverride"
    float m_viewDistRatioOverrideRadiusThreshold;            // +0x40 RTTR "ViewDistRatioOverrideRadiusThreshold"
    int m_useDissolve;                                       // +0x44 RTTR "UseDissolve"
    int m_streamBrushInstances;                              // +0x48 RTTR "StreamBrushInstances"
    int m_maxInstStreamingDataSizePerType;                   // +0x4C RTTR "MaxInstStreamingDataSizePerType"
    int m_maxInstStreamingDataSizeTotal;                     // +0x50 RTTR "MaxInstStreamingDataSizeTotal"
    int m_streamingFramesUntilUnload;                        // +0x54 RTTR "StreamingFramesUntilUnload"
    int m_streamingMaxReleasedPerFrame;                      // +0x58 RTTR "StreamingMaxReleasedPerFrame"
    int m_updateBatchSize;                                   // +0x5C RTTR "UpdateBatchSize"
    float m_updateBudgetMs;                                  // +0x60 RTTR "UpdateBudgetMs"
    int m_streamingFramesUntilObjectLoadingTimeout;          // +0x64 RTTR "StreamingFramesUntilObjectLoadingTimeout"
    int m_simulateSlowStreamingFrameCount;                   // +0x68 RTTR "SimulateSlowStreamingFrameCount"
    int m_debugDraw;                                         // +0x6C RTTR "DebugDraw"
    int m_debugSwitchingDistance;                            // +0x70 RTTR "DebugSwitchingDistance"
    int m_debugSelectedOnly;                                 // +0x74 RTTR "DebugSelectedOnly"
    int m_debugTypeFilter;                                   // +0x78 RTTR "DebugTypeFilter"
    int m_debugColoring;                                     // +0x7C RTTR "DebugColoring"
    int m_debugLabel;                                        // +0x80 RTTR "DebugLabel"
    std::uint8_t m_unknown84[4];                             // +0x84 unreflected
};

static_assert(offsetof(S_HLodConfig, m_clusterSwitchingDistanceMin) == 0x08,
              "S_HLodConfig::m_clusterSwitchingDistanceMin offset mismatch");
static_assert(offsetof(S_HLodConfig, m_vegetationSwitchingDistances) == 0x18,
              "S_HLodConfig::m_vegetationSwitchingDistances offset mismatch");
static_assert(offsetof(S_HLodConfig, m_switchingDistanceIn2D) == 0x30,
              "S_HLodConfig::m_switchingDistanceIn2D offset mismatch");
static_assert(offsetof(S_HLodConfig, m_updateBudgetMs) == 0x60,
              "S_HLodConfig::m_updateBudgetMs offset mismatch");
static_assert(offsetof(S_HLodConfig, m_debugLabel) == 0x80,
              "S_HLodConfig::m_debugLabel offset mismatch");
static_assert(sizeof(S_HLodConfig) == 0x88,
              "S_HLodConfig size mismatch");

}  // namespace wh::engine3d
