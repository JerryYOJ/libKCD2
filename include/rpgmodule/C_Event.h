#pragma once
#include <cstdint>
#include "I_Cause.h"

// -----------------------------------------------
// wh::rpgmodule::C_Event -- reputation-event wrapper that owns a freshly built I_Cause
// (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0x38 (PROVEN: ctor/emitter sub_1809DB5A4
// tracked-alloc 56, dword_1851DFB18 += 0x38).
// -----------------------------------------------
// RTTI TD rva 0x4D40F30, vtable rva 0x3A68568 (5 slots).  Ctor moves the cause pointer
// into +0x08 (source nulled -> ownership transfer), zeroes +0x10..+0x2F, then tail-calls
// own vtbl slot [3] (sub_1809DB684).  Cause factories build cause -> C_Event -> enrich
// with reputation entries (sub_1809DC874 / sub_180C5C484 / sub_180C66194) -> post to the
// global reputation-event manager *(qword_1853322A0+176) via its vfunc0 -> release via
// sub_1804FB980.  Slot roles other than [3]-called-at-ctor-tail are UNVERIFIED; [0]
// modeled as the dtor per standard MSVC layout [U].

namespace wh::rpgmodule {

class C_Event {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Event;
    virtual ~C_Event();       // [0] [U role]
    virtual void _vf1();      // [1] [U]
    virtual void _vf2();      // [2] [U]
    virtual void _vf3();      // [3] sub_1809DB684 -- invoked at ctor tail
    virtual void _vf4();      // [4] [U]

    I_Cause* m_pCause;        // +0x08  owned cause (moved in by sub_1809DB5A4; source nulled)
    uint8_t  m_repSlots[0x20];// +0x10..+0x2F  zeroed at ctor; reputation-entry slots [U layout]
    uint8_t  m_flag30;        // +0x30  byte flag (zeroed at ctor) [U role]
};
static_assert(sizeof(C_Event) == 0x38, "C_Event must be 0x38 (alloc 56 at sub_1809DB5A4)");

}  // namespace wh::rpgmodule
