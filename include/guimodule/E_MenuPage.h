#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::guimodule::E_MenuPage -- KCD2 WHGame.dll 1.5.6 (kd7u).  Enum wrapper, Type : uint8.
// -----------------------------------------------
// Nested-Type enum wrapper (rttr property mangling `W4Type@E_MenuPage@guimodule@wh@@`).
// Identity key of C_UIMenuPage (byte @element+0x08; C_MenuPageDatabase's
// DefaultKeyExtractor keys on it; runtime sorted-vector DB @0x185326860, 0x30 rows).
//
// ENUMERATORS VERIFIED from the 19 C_UIMenu::PreparePage (sub_180F69448) call sites --
// each builder passes its page id as an immediate and its widget set uniquely matches
// one menu_pages.xml row (full evidence: analysis/ui_survey/menu_page_builders.md §2-3;
// anchor: 14 = SoundSettings volume sliders 60/61/62).
// RTTR closes the two prior call-site gaps: None=0 and Credits=17. The remaining
// values retain their independently identified PreparePage call-site evidence.

namespace wh::guimodule {

struct E_MenuPage {
    enum Type : std::uint8_t {
        None                   = 0,
        RootMain               = 1,    // builder sub_180F6820C (also the mode-4 death variant)
        RootIngame             = 2,    // builder sub_1805598CC -- the in-game ESC pause menu
        RootPause              = 3,    // builder sub_182BAA95C -- restricted pause (save/settings disabled)
        SelectPlaylineNew      = 4,    // builder sub_182BAA8C0
        NewGameMode            = 5,    // builder sub_182BAAC18 (Normal/Hardcore)
        NewGameModeDebug       = 6,    // builder sub_181846FF0
        SelectPlaylineLoad     = 7,    // builder sub_182BAA7D8
        LoadGame               = 8,    // builder sub_182BAA354
        SaveGame               = 9,    // builder sub_182BA938C (overwrite-save list)
        Settings               = 10,   // builder sub_180559C6C (category hub)
        GameSettings           = 11,   // builder sub_180F6AD04
        GraphicSettings        = 12,   // builder sub_180F6C288
        AdvanceGraphicSettings = 13,   // builder sub_180F6B40C
        SoundSettings          = 14,   // builder sub_180F6A0E0 -- anchor
        Controls               = 15,   // builder sub_180F6A51C
        Keybinds               = 16,   // builder sub_180F68614
        Credits                = 17,
        HelpOverlays           = 18,   // builder sub_180821504
        DLCList                = 19,   // builder sub_182BA9D18
        RootPhotomode          = 20,   // builder sub_181F8DE50 (cvar-widget page)
    };
};
static_assert(sizeof(E_MenuPage::Type) == 1,
              "E_MenuPage::Type size mismatch");

}  // namespace wh::guimodule
