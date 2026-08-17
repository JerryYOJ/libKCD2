#pragma once

// -----------------------------------------------
// IVisAreaCallback -- Cry3DEngine vis-area listener (KCD2 WHGame.dll 1.5.6).
// sizeof 0x08.  2 slots (COL at vtable+0x10).
// -----------------------------------------------
// Standalone vtable 0x1845E4640. CParticleManager primary base @+0x00
// (vtable 0x18402AE60). Slot roles UNVERIFIED.

namespace Offsets {

struct IVisAreaCallback {
    virtual void _vf0() = 0;   // [0] 0x1834FE668
    virtual void _vf1() = 0;   // [1] 0x183503594
};
static_assert(sizeof(IVisAreaCallback) == 0x08, "IVisAreaCallback is a vptr-only interface");

}  // namespace Offsets
