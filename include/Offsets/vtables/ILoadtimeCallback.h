#pragma once

// -----------------------------------------------
// ILoadtimeCallback -- KCD2 binary vtable order. sizeof 0x08.
// -----------------------------------------------
// CFlashUI subobject @+0x30, vtable 0x18404A970. The order matches the CryEngine
// source interface: load-time update, load-time render, deleting destructor.

namespace Offsets {

struct ILoadtimeCallback {
    virtual void LoadtimeUpdate(float deltaTime) = 0;  // [0]
    virtual void LoadtimeRender() = 0;                 // [1]
    virtual void Dtor(char flags) = 0;                 // [2]
};

static_assert(sizeof(ILoadtimeCallback) == 0x08, "ILoadtimeCallback must be 0x08");

}  // namespace Offsets
