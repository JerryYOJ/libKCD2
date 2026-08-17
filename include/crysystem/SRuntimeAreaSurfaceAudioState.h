#pragma once
#include <cstddef>
#include <cstdint>

// Runtime-area surface audio state; canonical source name remains open.
struct SRuntimeAreaSurfaceAudioState {
    std::uint32_t m_audioTriggerId; // +0x00
    std::uint32_t m_audioRtpcId;    // +0x04
    float m_density;                // +0x08
};
static_assert(sizeof(SRuntimeAreaSurfaceAudioState) == 0x0C,
              "SRuntimeAreaSurfaceAudioState must be 0x0C");
