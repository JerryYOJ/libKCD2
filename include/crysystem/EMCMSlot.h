#pragma once
#include <cstdint>

enum EMCMSlot : std::int32_t {
    eMCMSlot_Game = 0,
    eMCMSlot_Animation,
    eMCMSlot_Cur,
    eMCMSlot_Prev,
    eMCMSlot_Debug,
    eMCMSlot_COUNT,
};
static_assert(sizeof(EMCMSlot) == 0x04, "EMCMSlot must be 0x04");
