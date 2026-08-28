#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

namespace wh::game {

class C_LevelSwitchData {
public:
    int GetTargetLevelId() const;                             // [0] 0x181A73290
    const CryStringT<char>& GetVideo() const;                 // [1] 0x181A72EC0
    int GetLoadingScreen() const;                             // [2] 0x181A727F0
    bool GetTargetLocationTransform(Matrix34& transform) const; // [3] 0x1819A3FC0
    float GetRealTimeDurationSeconds() const;                 // [4] 0x180D5ACC0
    std::int64_t GetWorldTimeDurationMilliseconds() const;    // [5] 0x180FC4890
    RTTR_ENABLE()                                             // [6..8]

    CryStringT<char> m_name;                                 // +0x08 RTTR "Name"
    CryStringT<char> m_video;                                // +0x10 RTTR "Video"
    CryStringT<char> m_targetLocationEntity;                 // +0x18 RTTR "TargetLocationEntity"
    int m_loadingScreen;                                     // +0x20 RTTR "LoadingScreen"
    int m_targetLevelId;                                     // +0x24 RTTR "TargetLevelId"
    std::int64_t m_worldTimeDurationInHours;                 // +0x28 RTTR "WorldTimeDurationInHours"
};

static_assert(offsetof(C_LevelSwitchData, m_name) == 0x08,
              "C_LevelSwitchData::m_name offset mismatch");
static_assert(offsetof(C_LevelSwitchData, m_targetLocationEntity) == 0x18,
              "C_LevelSwitchData::m_targetLocationEntity offset mismatch");
static_assert(offsetof(C_LevelSwitchData, m_targetLevelId) == 0x24,
              "C_LevelSwitchData::m_targetLevelId offset mismatch");
static_assert(offsetof(C_LevelSwitchData, m_worldTimeDurationInHours) == 0x28,
              "C_LevelSwitchData::m_worldTimeDurationInHours offset mismatch");
static_assert(sizeof(C_LevelSwitchData) == 0x30,
              "C_LevelSwitchData size mismatch");

}  // namespace wh::game
