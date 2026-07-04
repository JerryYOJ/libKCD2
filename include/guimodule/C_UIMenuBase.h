#pragma once
#include "guimodule/C_UIFlashBase.h"

// -----------------------------------------------
// wh::guimodule::C_UIMenuBase -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x58.
// -----------------------------------------------
// RTTI .?AVC_UIMenuBase@guimodule@wh@@ (TD 0x184CD9A88).
// Bases: C_UIFlashBase @+0x00 (COL 0x41353B0), IUIElementEventListener @+0x10
// (COL 0x41353D8). vtables: primary 0x183A815A0 (14 slots, no additions), listener
// 0x183A81070 (8 slots). ctor sub_180BC7F58 = C_UIFlashBase ctor + own vtables;
// adds NO members and NO virtuals.
//
// Menu-family flash base: pins the flash element to the shared "Menu" movie --
// GetElementName override [11] sub_181A8F230 returns the literal "Menu", so every
// C_UIMenuBase-derived screen (C_UIMenu and the menu leaves) binds to the same
// IUIElement. Init [1] sub_180EC781C is a pure thunk to C_UIFlashBase::Init
// (sub_180565D38); Deinit [2] sub_182BA6F40 extends the base unbind.
//
// [FUNDAMENTAL vs KCD1] KCD1's menu spine was C_UIHUDElements/C_UIMenuEvents event
// systems on CUIManager; KCD2 folds "a screen living inside the Menu movie" into this
// empty flash-base specialization.

namespace wh::guimodule {

class C_UIMenuBase : public C_UIFlashBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIMenuBase;
    const char* GetElementName() const override;   // [11] 0x181A8F230  = "Menu"
};
static_assert(sizeof(C_UIMenuBase) == 0x58, "C_UIMenuBase must be 0x58");

}  // namespace wh::guimodule
