#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::guimodule::C_UISaveLoad -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x128.
// -----------------------------------------------
// *** OPAQUE SHELL -- G2 spine wave provides size + anchors only; the G3 wave owns the
// *** member breakdown. Do NOT treat the byte blob below as layout knowledge.
//
// RTTI .?AVC_UISaveLoad@guimodule@wh@@. ctor sub_1805FF494 (in-place; three vtable
// writes at +0x00/+0x10/+0x58 => same MI shape family as the menu classes). Lives
// EMBEDDED in C_UIMenu at +0xB0 (ctor call @0x1805ff429; next member at +0x1D8 pins
// sizeof = 0x128). Registers the save/load CVar block: wh_sys_NoPlaylineDeleting,
// wh_sys_NoSavePotion, wh_ui_DisableNewGameDebugFader, wh_mod_ShowUsedModsInSaveTooltip,
// wh_sys_ShowInfoInSaveTooltip, wh_sys_ShowDlcInSaveTooltip, wh_sys_LoadGameFilter;
// holds the "BeforeNewGame" playline tag.
//
// [MODERATE vs KCD1] KCD1 C_UISaveLoad was a CUIManager-registered event system; KCD2
// demotes it to a value member of C_UIMenu.

namespace wh::guimodule {

class C_UISaveLoad {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UISaveLoad;
    uint8_t _opaque[0x128];   // size-proven shell; real fields include 3 vfptrs (+0x00/+0x10/+0x58) and cached ICVar*s
};
static_assert(sizeof(C_UISaveLoad) == 0x128, "C_UISaveLoad must be 0x128");

}  // namespace wh::guimodule
