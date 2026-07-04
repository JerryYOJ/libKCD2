#pragma once
#include <cstdint>
#include <cstddef>

struct ICVar;

// -----------------------------------------------
// wh::dialogmodule::C_PlayerDialogController -- the player's side of a conversation
// (KCD2 1.5.6, kd7u).  sizeof 0x178 (operator new(376) in C_DialogInstance::Init).
// -----------------------------------------------
// RTTI TD 0x184B53508; vtable 0x183E696B0 (1 slot: deleting dtor); ctor
// sub_181E6E870(this, scene, handle); dtor sub_180C06F28 -> sub_180C07688. Created by
// C_DialogInstance::Init when the player participates (stored at instance +0x2E8; freed
// FIRST in the instance dtor). Subscribes two delegates to scene+200/+216. Saves and
// restores two render CVars across the conversation (r_Sharpening @+0xF0,
// e_svoTI_RsmConeMaxLengthFOVMulEnabled @+0x100).
// CHEAT: +0x140..+0x168 hold the player choice/decision vectors (16-byte-stride
// records) -- the place to force/unlock available responses. WHICH vector is the
// visible list is UNVERIFIED, as is the exact container split (modeled opaque).

namespace wh::dialogmodule {

class C_PlayerDialogController {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PlayerDialogController;
    virtual ~C_PlayerDialogController();   // [0] (only vtable slot)

    void*    m_pScene;                // +0x08  owning scene/interaction runtime
    uint64_t _q10;                    // +0x10  [not walked]
    uint8_t  m_inputMap[0x40];        // +0x18..+0x57  input/decision map obj A [~64B, layout UNVERIFIED]
    uint8_t  m_decisionMap[0x40];     // +0x58..+0x97  input/decision map obj B [~64B, layout UNVERIFIED]
    uint8_t  _unk98[0x18];            // +0x98..+0xAF  [not walked]
    void*    m_pRegistrar;            // +0xB0  &unk_185579380 (static registration record)
    uint8_t  _unkB8[0x38];            // +0xB8..+0xEF  [not walked]
    ICVar*   m_pCVarSharpening;       // +0xF0  "r_Sharpening" (saved/restored)
    uint64_t _qF8;                    // +0xF8  [not walked]
    ICVar*   m_pCVarSvoTI;            // +0x100 "e_svoTI_RsmConeMaxLengthFOVMulEnabled"
    uint8_t  _unk108[0x38];           // +0x108..+0x13F  [not walked]
    uint8_t  m_decisionVecs[0x28];    // +0x140..+0x167  player choice/decision vectors
                                      //   (16B-stride records; container split UNVERIFIED)  <-- CHEAT
    uint64_t _q168;                   // +0x168  [not walked]
    uint64_t _q170;                   // +0x170  [not walked]
};
static_assert(sizeof(C_PlayerDialogController) == 0x178, "C_PlayerDialogController must be 0x178 (alloc 376)");
static_assert(offsetof(C_PlayerDialogController, m_pCVarSharpening) == 0xF0);
static_assert(offsetof(C_PlayerDialogController, m_decisionVecs) == 0x140);

}  // namespace wh::dialogmodule
