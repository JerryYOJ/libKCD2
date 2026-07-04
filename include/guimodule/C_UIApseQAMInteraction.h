#pragma once
#include <cstdint>
#include "guimodule/C_UIBase.h"
#include "framework/C_Signal.h"

// -----------------------------------------------
// wh::guimodule::C_UIApseQAMInteraction -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x98.
// -----------------------------------------------
// RTTI .?AVC_UIApseQAMInteraction@guimodule@wh@@ (TD 0x184C925A0). Base C_UIBase only;
// ctor sub_180BEADFC. vtable 0x183ED8F38 (10 slots): [0] dtor 0x182AFD774,
// [1] Init 0x180ED2BF4, [2] Deinit 0x182AFE66C, [4] Update = nullsub (no per-frame work).
// Embedded BY VALUE in C_UIApseInventory @+0xA30 (spans to the inventory end 0xAC8).
//
// Quick-access-menu interaction glue for the Apse inventory. Member roles beyond the
// three signals UNVERIFIED (the sub_181F47880 sub-object tail lost registers in the
// decompile -- G4a dossier §4).

namespace wh::guimodule {

class C_UIApseQAMInteraction : public C_UIBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIApseQAMInteraction;
    wh::shared::C_Signal<> m_signal10;   // +0x10  delegate table &unk_185669248 [signature UNVERIFIED]
    wh::shared::C_Signal<> m_signal20;   // +0x20  delegate table &unk_185669238 [signature UNVERIFIED]
    uint8_t                m_unk30[0x10]; // +0x30  sub_181F47880(this+0x30, owner, this) sub-object [identity UNVERIFIED]
    wh::shared::C_Signal<> m_signal40;   // +0x40  delegate table &unk_185665430 [signature UNVERIFIED]
    uint64_t               m_unk50;      // +0x50  ctor 0 [role UNVERIFIED]
    bool                   m_flag58;     // +0x58  ctor 0 [role UNVERIFIED]
    uint8_t                _pad59[7];    // +0x59
    uint64_t               m_unk60;      // +0x60  ctor 0
    uint64_t               m_unk68;      // +0x68  ctor 0
    uint64_t               m_unk70;      // +0x70  ctor 0
    int32_t                m_int78;      // +0x78  ctor 0
    uint8_t                _unk7C[0x1C]; // +0x7C..+0x98  ctor-untouched / lost to decompile truncation [UNVERIFIED]
};
static_assert(sizeof(C_UIApseQAMInteraction) == 0x98, "C_UIApseQAMInteraction must be 0x98");
static_assert(offsetof(C_UIApseQAMInteraction, m_signal40) == 0x40, "third signal at 0x40");

}  // namespace wh::guimodule
