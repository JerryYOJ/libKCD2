#pragma once
#include <cstdint>

// -----------------------------------------------
// 8-byte score out-param of I_ObjectivePlannerRunnable::GetScore
// (KCD2 WHGame.dll 1.5.6). [SYNTHETIC NAME]
// -----------------------------------------------
// Slot 1 writes {float, uint16 extra=0}. Band table 0x180395CCC maps 0→-1, 2→10 … 10→90.

namespace wh::xgenaimodule::activitysystem {

struct S_ObjectiveScore {
    float    m_score;  // +0x00
    uint16_t m_band;   // +0x04
    uint16_t _pad06;   // +0x06
};
static_assert(sizeof(S_ObjectiveScore) == 0x08,
              "GetScore out-param is float + u16");

}  // namespace wh::xgenaimodule::activitysystem
