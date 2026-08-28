#pragma once
#include <cstddef>
#include <cstdint>

struct SStreamingPredictionZone {
    std::int32_t m_roundId : 31;                                // +0x00 bits 0..30
    std::int32_t m_highPriority : 1;                            // +0x00 bit 31
    float m_minMipFactor;                                       // +0x04
};

static_assert(offsetof(SStreamingPredictionZone, m_minMipFactor) == 0x04,
              "SStreamingPredictionZone mip-factor offset mismatch");
static_assert(sizeof(SStreamingPredictionZone) == 0x08,
              "SStreamingPredictionZone size mismatch");
