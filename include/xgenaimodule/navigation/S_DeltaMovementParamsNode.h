#pragma once
#include <cstddef>
#include <cstdint>
#include "../../wh/S_DeltaMovementSpeedParams.h"
#include "../../wh/S_RotationAngleComputerParams.h"

namespace wh::xgenaimodule::navigation {

struct S_DeltaMovementParamsNode {
    int m_logicalSpeedId;                                   // +0x00 RTTR "LogicalSpeedId"
    wh::S_RotationAngleComputerParams m_rotationParams;     // +0x04 RTTR "RotationParams"
    wh::S_DeltaMovementSpeedParams m_speedParams;           // +0x20 RTTR "SpeedParams"
    float m_moveTargetSmoothingAngularSpeed;                // +0x38 RTTR "MoveTargetSmoothingAngularSpeed"
    std::uint8_t _pad3C[4];                                 // +0x3C
};

static_assert(offsetof(S_DeltaMovementParamsNode, m_rotationParams) == 0x04,
              "S_DeltaMovementParamsNode::m_rotationParams offset mismatch");
static_assert(offsetof(S_DeltaMovementParamsNode, m_speedParams) == 0x20,
              "S_DeltaMovementParamsNode::m_speedParams offset mismatch");
static_assert(offsetof(S_DeltaMovementParamsNode, m_moveTargetSmoothingAngularSpeed) == 0x38,
              "S_DeltaMovementParamsNode::m_moveTargetSmoothingAngularSpeed offset mismatch");
static_assert(sizeof(S_DeltaMovementParamsNode) == 0x40,
              "S_DeltaMovementParamsNode size mismatch");

}  // namespace wh::xgenaimodule::navigation
