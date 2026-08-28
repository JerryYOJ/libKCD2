#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::S_DeltaMovementSpeedParamsSubRange
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x14. No vtable.
// -----------------------------------------------

namespace wh {

struct S_DeltaMovementSpeedParamsSubRange {
    float m_inputMin;                                     // +0x00 RTTR "InputMin"
    float m_inputMax;                                     // +0x04 RTTR "InputMax"
    std::int32_t m_pseudoSpeedSlowDown;                   // +0x08 RTTR "PseudoSpeedSlowDown"
    float m_resetAngularSpeedOnSignChange;                // +0x0C RTTR "ResetAngularSpeedOnSignChange"
    float m_targetThrottleMax;                            // +0x10 RTTR "TargetThrottleMax"
};

static_assert(offsetof(S_DeltaMovementSpeedParamsSubRange, m_inputMin) == 0x00,
              "S_DeltaMovementSpeedParamsSubRange::m_inputMin offset mismatch");
static_assert(sizeof(S_DeltaMovementSpeedParamsSubRange) == 0x14,
              "S_DeltaMovementSpeedParamsSubRange size mismatch");

}  // namespace wh
