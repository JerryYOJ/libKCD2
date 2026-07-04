#pragma once
#include <cstdint>
#include <functional>
#include "guimodule/C_UIFlashBase.h"

// -----------------------------------------------
// wh::guimodule::C_UIModalDialogHealing -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x100.
// -----------------------------------------------
// RTTI .?AVC_UIModalDialogHealing@guimodule@wh@@ (TD 0x184C9EB98).
// Bases: C_UIFlashBase @+0x00, IUIElementEventListener @+0x10. vtables: primary
// 0x183D144F0 (14 slots; overrides [1] Init 0x18183D3AC), listener (8).
//
// Healing-item modal, flash element "ApseModalDialog". Init registers:
//   "OnHealingDialogConfirmClicked" -> sub_182B13B34 (void(), via sub_180613AE8)
//   "OnHealingDialogCancelClicked"  -> sub_182B1398C (void())
//   "OnGetHealEffect"               -> sub_182B13EC8 -- registered via a DIFFERENT
//     helper (sub_18183D498): a non-void dispatcher, likely returning the selected
//     heal effect to flash; signature UNVERIFIED.
// Embedded BY VALUE in C_UIApseInventory @+0x5E8 (size pinned by the next embed
// C_UIModalDialogCombine @+0x6E8; 0x18 larger than the Question shape -- the extra
// space holds the heal-effect delegate state). Member breakdown beyond the two
// callbacks UNVERIFIED.

namespace wh::guimodule {

class C_UIModalDialogHealing : public C_UIFlashBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIModalDialogHealing;
    std::function<void()> m_onConfirm;    // +0x58  (0x40) "OnHealingDialogConfirmClicked" [role from name]
    std::function<void()> m_onCancel;     // +0x98  (0x40) "OnHealingDialogCancelClicked" [role from name]
    uint8_t               _unkD8[0x28];   // +0xD8..+0x100  heal-effect delegate state ("OnGetHealEffect"); layout UNVERIFIED
};
static_assert(sizeof(C_UIModalDialogHealing) == 0x100, "C_UIModalDialogHealing must be 0x100");
static_assert(offsetof(C_UIModalDialogHealing, m_onCancel) == 0x98, "second callback at 0x98");

}  // namespace wh::guimodule
