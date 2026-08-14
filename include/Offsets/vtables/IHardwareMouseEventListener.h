#pragma once
#include <cstdint>

// -----------------------------------------------
// IHardwareMouseEventListener -- KCD2 binary vtable order. sizeof 0x08.
// -----------------------------------------------
// CFlashUI subobject @+0x08, vtable 0x18404A7C0. Slot [0] is a deleting-destructor
// thunk; slot [1] receives x/y, EHARDWAREMOUSEEVENT, and wheel delta.

namespace Offsets {

struct IHardwareMouseEventListener {
    virtual void Dtor(char flags) = 0;  // [0]
    virtual void OnHardwareMouseEvent(int32_t x, int32_t y,
                                      int32_t event, int32_t wheelDelta) = 0;  // [1]
};

static_assert(sizeof(IHardwareMouseEventListener) == 0x08,
              "IHardwareMouseEventListener must be 0x08");

}  // namespace Offsets
