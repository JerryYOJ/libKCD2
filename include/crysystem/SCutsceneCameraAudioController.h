#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"

struct SCutsceneCameraAudioController {
    Vec3 m_activeLookOffset;                      // +0x00
    std::uint32_t m_activeCutsceneCount;          // +0x0C
    std::uint32_t m_flaggedCutsceneCount;         // +0x10
    std::byte m_open14[0x14];                     // +0x14
    float m_threshold250;                         // +0x28, initialized 250.0f; role OPEN
    std::uint32_t m_cutsceneAudioControlId;       // +0x2C
    float m_savedVaBlendCullingThreshold;         // +0x30
    Vec3 m_pendingLookOffset;                     // +0x34
    std::byte m_open40[0x0C];                     // +0x40
    float m_pendingParameter;                     // +0x4C, initialized 3.0f; role OPEN
    bool m_pendingStateValid;                     // +0x50
    std::byte m_tail51[0x07];                     // +0x51
};
static_assert(sizeof(SCutsceneCameraAudioController) == 0x58,
              "SCutsceneCameraAudioController must be 0x58");
static_assert(offsetof(SCutsceneCameraAudioController, m_cutsceneAudioControlId) == 0x2C,
              "cutscene audio control must be at 0x2C");
static_assert(offsetof(SCutsceneCameraAudioController, m_pendingStateValid) == 0x50,
              "cutscene pending-state flag must be at 0x50");
