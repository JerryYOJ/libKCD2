#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::guimodule::C_UISettings -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x490.
// -----------------------------------------------
// *** OPAQUE SHELL -- G2 spine wave provides size + anchors only; the G3 wave owns the
// *** member breakdown. Do NOT treat the byte blob below as layout knowledge.
//
// RTTI .?AVC_UISettings@guimodule@wh@@. ctor sub_180600544 (in-place; four vtable
// writes at +0x00/+0x10/+0x58/+0x60). Lives EMBEDDED in C_UIMenu at +0x1D8 (ctor call
// @0x1805ff438; C_UIMenu tail members at +0x668 pin sizeof = 0x490). Registers the
// settings/consent CVar block: wh_ui_eulaConfirmedVersion, wh_ui_eulaCurrentVersion,
// wh_ui_telemetryConfirmed, wh_ui_consoleModeChosen, wh_ui_dlcOverlayShown[Owned],
// wh_ui_SubtitlesEnabled, wh_ui_BubblesEnabled, ...; hooks the "SpecsChange" event.
//
// [FUNDAMENTAL vs KCD1] KCD1's CUISettings was a CUIManager-registered event system;
// KCD2 demotes it to a value member of C_UIMenu.

namespace wh::guimodule {

class C_UISettings {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UISettings;
    uint8_t _opaque[0x490];   // size-proven shell; real fields include 4 vfptrs (+0x00/+0x10/+0x58/+0x60)
};
static_assert(sizeof(C_UISettings) == 0x490, "C_UISettings must be 0x490");

}  // namespace wh::guimodule
