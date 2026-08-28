#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "S_JointDelta.h"

namespace wh::animationmodule::JointPoseMorphData {

struct S_Pose {
    void OnAfterDeserialization();                         // 0x180BA1218

    std::uint32_t m_nameHash;                              // +0x00 ASCII-case-insensitive CRC32
    std::uint8_t m_unknown04[4];                           // +0x04 unreflected
    std::vector<S_JointDelta> m_jointDeltas;               // +0x08 RTTR "JointDeltas"
};

static_assert(offsetof(S_Pose, m_nameHash) == 0x00,
              "S_Pose::m_nameHash offset mismatch");
static_assert(offsetof(S_Pose, m_jointDeltas) == 0x08,
              "S_Pose::m_jointDeltas offset mismatch");
static_assert(sizeof(S_Pose) == 0x20, "S_Pose size mismatch");

}  // namespace wh::animationmodule::JointPoseMorphData
