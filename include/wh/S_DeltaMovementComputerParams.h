#pragma once
#include <cstddef>

// -----------------------------------------------
// wh::S_DeltaMovementComputerParams
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. No vtable.
// -----------------------------------------------

namespace wh {

struct S_DeltaMovementComputerParams {
    float m_deltaMovementDirectionThreshold;              // +0x00 RTTR "DeltaMovementDirectionThreshold"
    float m_moveTargetSmoothingThreshold;                 // +0x04 RTTR "MoveTargetSmoothingThreshold"
    float m_resetAngularSpeedOnSignChange;                // +0x08 RTTR "ResetAngularSpeedOnSignChange"
    float m_minDistanceToPathEnd;                         // +0x0C RTTR "MinDistanceToPathEnd"
};

static_assert(offsetof(S_DeltaMovementComputerParams, m_deltaMovementDirectionThreshold) == 0x00,
              "S_DeltaMovementComputerParams::m_deltaMovementDirectionThreshold offset mismatch");
static_assert(sizeof(S_DeltaMovementComputerParams) == 0x10,
              "S_DeltaMovementComputerParams size mismatch");

}  // namespace wh
