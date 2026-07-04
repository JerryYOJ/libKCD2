#pragma once
#include <cstdint>
#include "guimodule/I_Cutscene.h"

// -----------------------------------------------
// wh::guimodule::C_RenderedCutscene -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0xD8 (ALLOC-PROVEN).
// -----------------------------------------------
// RTTI TD 0x184CB0750; vtable 0x183EE1DB8. The pre-rendered VIDEO cutscene leaf.
// Bases: I_Cutscene@+0x00 + empty CryDeferrable<0> @+0x61 (CHD; not modeled -- covered
// by the +0x60 pad below). ctor sub_1811CF7E8; creator sub_1811CF6AC (alloc 0xD8
// @0x1811cf6da). The ONLY leaf overriding the defaulted [8] (0x181F58CE0). Own slots:
// [0] 0x182B361BC, [1] 0x182B384C8, [2] 0x1819E09B0, [3] 0x182B37E4C, [4] nullsub,
// [5] 0x182B38F00, [6] 0x181A78EB0, [7] 0x182B377AC, [8] 0x181F58CE0.

namespace wh::guimodule {

class C_RenderedCutscene : public I_Cutscene {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RenderedCutscene;
    void Play() override;            // [1] 0x182B384C8
    void Stop() override;            // [2] 0x1819E09B0
    void Update() override;          // [3] 0x182B37E4C
    void Reset() override;           // [4] nullsub
    void _vf5() override;            // [5] 0x182B38F00
    int  GetType() const override;   // [6] 0x181A78EB0
    bool IsActive() const override;  // [7] 0x182B377AC
    void _vf8() override;            // [8] 0x181F58CE0 -- only leaf overriding the default [role UNVERIFIED]

    uint8_t          _pad60[8];      // +0x60  (CryDeferrable<0> empty base @+0x61 per CHD)
    CryStringT<char> m_str68;        // +0x68  ctor magic-static [role UNVERIFIED -- video path?]
    CryStringT<char> m_str70;        // +0x70  ctor [role UNVERIFIED]
    uint8_t          _unk78[0x18];   // +0x78..+0x90  ctor-zeroed [UNVERIFIED]
    uint8_t          m_byte90;       // +0x90  ctor 1
    uint8_t          m_byte91;       // +0x91  ctor 1
    uint8_t          m_byte92;       // +0x92  ctor 0
    uint8_t          _pad93[5];      // +0x93
    uint8_t          _unk98[0x28];   // +0x98..+0xC0  ctor-zeroed [UNVERIFIED]
    int32_t          m_intC0;        // +0xC0  ctor 0
    uint8_t          _padC4[4];      // +0xC4
    uint64_t         m_unkC8;        // +0xC8  ctor 0
    uint64_t         m_unkD0;        // +0xD0  ctor 0
};
static_assert(sizeof(C_RenderedCutscene) == 0xD8, "C_RenderedCutscene must be 0xD8 (creator sub_1811CF6AC)");

}  // namespace wh::guimodule
