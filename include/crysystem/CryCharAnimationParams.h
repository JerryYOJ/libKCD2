#pragma once
#include <cstddef>
#include <cstdint>

// Current source-compatible Cry animation-start parameters without the stale
// CryCommon serialization dependency graph.
struct CryCharAnimationParams {
    float m_fTransTime;            // +0x00
    float m_fKeyTime;              // +0x04
    float m_fPlaybackSpeed;        // +0x08
    float m_fAllowMultilayerAnim;  // +0x0C
    std::int32_t m_nLayerID;       // +0x10
    float m_fPlaybackWeight;       // +0x14
    std::uint32_t m_nFlags;        // +0x18
    std::uint32_t m_nUserToken;    // +0x1C
    float m_fUserData[8];          // +0x20
};
static_assert(sizeof(CryCharAnimationParams) == 0x40,
              "CryCharAnimationParams must be 0x40");
static_assert(alignof(CryCharAnimationParams) == 0x04,
              "CryCharAnimationParams alignment must be 0x04");
static_assert(offsetof(CryCharAnimationParams, m_fUserData) == 0x20,
              "animation user data must be at 0x20");
