#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::framework {
class S_SaveGameDebugInfo {
public:
    virtual ~S_SaveGameDebugInfo();
    RTTR_ENABLE()  // [1..3]
    CryStringT<char> m_buildTime;  // +0x8 RTTR "BuildTime"
    CryStringT<char> m_buildComputer;  // +0x10 RTTR "BuildComputer"
    CryStringT<char> m_buildDescription;  // +0x18 RTTR "BuildDescription"
    CryStringT<char> m_configuration;  // +0x20 RTTR "Configuration"
    CryStringT<char> m_buildInfo;  // +0x28 RTTR "BuildInfo"
    CryStringT<char> m_userName;  // +0x30 RTTR "UserName"
};

static_assert(offsetof(S_SaveGameDebugInfo, m_configuration) == 0x20, "S_SaveGameDebugInfo::m_configuration offset mismatch");
static_assert(offsetof(S_SaveGameDebugInfo, m_buildDescription) == 0x18, "S_SaveGameDebugInfo::m_buildDescription offset mismatch");
static_assert(offsetof(S_SaveGameDebugInfo, m_buildComputer) == 0x10, "S_SaveGameDebugInfo::m_buildComputer offset mismatch");
static_assert(offsetof(S_SaveGameDebugInfo, m_buildTime) == 0x8, "S_SaveGameDebugInfo::m_buildTime offset mismatch");
static_assert(sizeof(S_SaveGameDebugInfo) == 0x38, "S_SaveGameDebugInfo size mismatch");

}  // namespace wh::framework
