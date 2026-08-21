#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::I_LabelTracker -- KCD2 WHGame.dll.  sizeof 8.  4 slots.
// -----------------------------------------------
// RTTI .?AVI_LabelTracker@xgenaimodule@wh@@. Primary base of entitymodule::C_RiderPlayerControl
// (vt 0x183A6CA50). Slot [3] 0x18100CE30 is the deleting-dtor target of the ISystemEventListener
// adjustor at control+8.

namespace wh::xgenaimodule {

class I_LabelTracker {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_LabelTracker;
    virtual void SetLabelArmed() = 0;          // [0] 0x1808EF440  Control+0x38 = 1
    virtual void ClearLabelArmed() = 0;        // [1] 0x181A718F0  Control+0x38 = 0
    virtual void unk_10() = 0;                 // [2] 0x1803B6E80  nullsub
    virtual void Destroy(uint8_t dealloc) = 0; // [3] 0x18100CE30
};
static_assert(sizeof(I_LabelTracker) == 8, "I_LabelTracker is vtable-only");

}  // namespace wh::xgenaimodule
