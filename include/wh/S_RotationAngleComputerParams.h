#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::S_RotationAngleComputerParams
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x1C. No vtable.
// -----------------------------------------------
// RTTR name "AngularSpeedSmothingTime" preserves the shipped spelling.

namespace wh {

struct S_RotationAngleComputerParams {
    float m_minAngularDiff;                               // +0x00 RTTR "MinAngularDiff"
    float m_maxAngularDiff;                               // +0x04 RTTR "MaxAngularDiff"
    float m_minAngularSpeed;                              // +0x08 RTTR "MinAngularSpeed"
    float m_maxAngularSpeed;                              // +0x0C RTTR "MaxAngularSpeed"
    float m_angularSpeedSmothingTime;                     // +0x10 RTTR "AngularSpeedSmothingTime"
    bool m_resetAngularSpeedOnSignChange;                 // +0x14 RTTR "ResetAngularSpeedOnSignChange"
    std::uint8_t _pad15[3];                               // +0x15
    float m_oppositeSideAngDifferenceThreshold;           // +0x18 RTTR "OppositeSideAngDifferenceThreshold"
};

static_assert(offsetof(S_RotationAngleComputerParams, m_oppositeSideAngDifferenceThreshold) == 0x18,
              "S_RotationAngleComputerParams::m_oppositeSideAngDifferenceThreshold offset mismatch");
static_assert(sizeof(S_RotationAngleComputerParams) == 0x1C,
              "S_RotationAngleComputerParams size mismatch");

}  // namespace wh
