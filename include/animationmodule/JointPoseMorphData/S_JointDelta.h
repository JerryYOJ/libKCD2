#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/Cry_Math.h"

namespace wh::animationmodule::JointPoseMorphData {

struct S_JointDelta {
    std::uint32_t m_nameHash;                               // +0x00 ASCII-case-insensitive CRC32
    Vec3 m_deltaT;                                          // +0x04 RTTR "DeltaT"
    Ang3 m_deltaR;                                          // +0x10 RTTR "DeltaR"
};

static_assert(offsetof(S_JointDelta, m_nameHash) == 0x00,
              "S_JointDelta::m_nameHash offset mismatch");
static_assert(offsetof(S_JointDelta, m_deltaT) == 0x04,
              "S_JointDelta::m_deltaT offset mismatch");
static_assert(offsetof(S_JointDelta, m_deltaR) == 0x10,
              "S_JointDelta::m_deltaR offset mismatch");
static_assert(sizeof(S_JointDelta) == 0x1C,
              "S_JointDelta size mismatch");

}  // namespace wh::animationmodule::JointPoseMorphData
