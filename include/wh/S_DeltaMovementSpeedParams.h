#pragma once
#include <cstddef>
#include <vector>
#include "S_DeltaMovementSpeedParamsSubRange.h"

// -----------------------------------------------
// wh::S_DeltaMovementSpeedParams
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x18. No vtable.
// -----------------------------------------------

namespace wh {

struct S_DeltaMovementSpeedParams {
    std::vector<S_DeltaMovementSpeedParamsSubRange> m_subRanges; // +0x00 RTTR "SubRanges"
};

static_assert(offsetof(S_DeltaMovementSpeedParams, m_subRanges) == 0x00,
              "S_DeltaMovementSpeedParams::m_subRanges offset mismatch");
static_assert(sizeof(S_DeltaMovementSpeedParams) == 0x18,
              "S_DeltaMovementSpeedParams size mismatch");

}  // namespace wh
