#pragma once
#include <boost/container/vector.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../../CryEngine/CryCommon/CryString.h"
#include "S_Pose.h"

namespace wh::animationmodule::JointPoseMorphData {

struct S_Model {
    void OnAfterDeserialization();                         // 0x180BA1FD8

    CryStringT<char> m_name;                               // +0x00 RTTR "Name"
    std::vector<S_Pose> m_poses;                           // +0x08 RTTR "Poses"
    boost::container::vector<std::uint32_t> m_jointNameHashes; // +0x20 sorted unique cache
};

static_assert(offsetof(S_Model, m_name) == 0x00,
              "S_Model::m_name offset mismatch");
static_assert(offsetof(S_Model, m_poses) == 0x08,
              "S_Model::m_poses offset mismatch");
static_assert(offsetof(S_Model, m_jointNameHashes) == 0x20,
              "S_Model::m_jointNameHashes offset mismatch");
static_assert(sizeof(S_Model) == 0x38, "S_Model size mismatch");

}  // namespace wh::animationmodule::JointPoseMorphData
