#pragma once
#include <cstdint>
#include "guimodule/C_UIFlashObject.h"

// -----------------------------------------------
// wh::guimodule::C_UIFlashCharacterArmorStatSub -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x28 (ALLOC-PROVEN).
// -----------------------------------------------
// C_UIFlashObject serialization record (flash_leaves.md §1). Creator sub_1808F60DC
// N=56 (ctor 0x1808F61B4). FillUIArgs override 0x1805570DC (two floats, inline tag-1
// builder). Element of C_UIFlashCharacterArmorStat::m_subs.

namespace wh::guimodule {

class C_UIFlashCharacterArmorStatSub : public C_UIFlashObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIFlashCharacterArmorStatSub;
    void FillUIArgs(void* pArgs) const override;   // [1] 0x1805570DC

    float   m_val0;      // +0x18
    float   m_val1;      // +0x1C
    uint8_t _unk20[8];   // +0x20..+0x28  ctor tail, not serialized [UNVERIFIED]
};
static_assert(sizeof(C_UIFlashCharacterArmorStatSub) == 0x28, "C_UIFlashCharacterArmorStatSub must be 0x28 (creator sub_1808F60DC)");

}  // namespace wh::guimodule
