#pragma once
#include <cstdint>
#include "guimodule/I_FaderListener.h"

// -----------------------------------------------
// wh::guimodule::C_FaderSuspend -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x28 (INFERRED).
// -----------------------------------------------
// RTTI TD 0x184CB0B30; COL 0x4139140; vtable 0x183A85A28. Base: I_FaderListener@+0x00.
// RAII fade-suspend guard: ctors sub_180C08FF8 / sub_180C09154 resolve the fader
// (sub_1806D6B2C) and register self via fader vf[24]/vf[32]. NO standalone alloc site
// observed (stack/embedded use) -- sizeof 0x28 is the ctor-write extent, UNVERIFIED.

namespace wh::guimodule {

class C_FaderSuspend : public I_FaderListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FaderSuspend;
    // I_FaderListener impls (vtable 0x183A85A28; roles UNVERIFIED).
    void OnFadeIn() override;    // [1] 0x180C08FC4
    void OnFadeOut() override;   // [2] 0x180C08F10
    void OnFade() override;      // [3] 0x180C08EA4

    void*             m_pFader;     // +0x08  resolved fader reference (sub_1806D6B2C)
    volatile int32_t* m_pRefCount;  // +0x10  smart-ptr control
    CryStringT<char>  m_name;       // +0x18  [role UNVERIFIED]
    uint8_t           m_unk20[8];   // +0x20  sub_1821386D0 obj [type UNVERIFIED]
};
static_assert(sizeof(C_FaderSuspend) == 0x28, "C_FaderSuspend ~0x28 (ctor extent; no alloc site -- UNVERIFIED)");

}  // namespace wh::guimodule
