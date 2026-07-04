#pragma once
#include <cstdint>
#include "guimodule/C_UIMenuBase.h"
#include "guimodule/I_UIMenu.h"
#include "guimodule/C_UISaveLoad.h"
#include "guimodule/C_UISettings.h"
#include "framework/C_Signal.h"
#include "Offsets/vtables/IActionListener.h"
#include "Offsets/vtables/ISystem.h"   // Offsets::ISystemEventListener

// -----------------------------------------------
// wh::guimodule::C_UIMenu -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x698.
// -----------------------------------------------
// RTTI .?AVC_UIMenu@guimodule@wh@@ (TD 0x184CD9A28). ctor sub_1805FF380; created by the
// rttr as_std_shared_ptr factory sub_1805FF260 (alloc 0x698 -> shared_ptr adopt
// sub_1805FF2EC, _Ref_count<C_UIMenu> vtable 0x183A409E8) during the C_GUIModule::Init
// screen enumeration.
// Bases/COLs: C_UIMenuBase @+0x00 (0x4381DA8), IUIElementEventListener @+0x10
// (0x4381D80), wh::I_UIMenu @+0x58 (0x4381D08), IActionListener @+0x60 (0x4381CE0),
// ISystemEventListener @+0x68 (0x4381D58). vtables: primary 0x183EF5A60 (14 slots, no
// additions beyond C_UIFlashBase), I_UIMenu 0x183EF5958, IActionListener 0x183EF5938,
// ISystemEventListener 0x183EF59F8, listener 0x183EF5A18.
//
// The main-menu / pause-menu facade screen: binds the "Menu" flash element (via
// C_UIMenuBase), embeds the save/load and settings sub-controllers by value, exposes
// the wh::I_UIMenu control surface to the rest of the game, listens to action-map
// input (OnAction 0x180557658 forwards ("SetInput", action, activationMode) to flash
// when the +0xA0 state byte is set) and to system events. ctor registers CVar
// "wh_ui_showFirstTimeOverlays" (default from pSystem vf[+0x668]() == 0).
//
// [FUNDAMENTAL vs KCD1] KCD1 had no single menu object -- menu flow was spread over
// CUIManager's C_UIMenuEvents/C_UIHUDElements event systems. KCD2 folds it into this
// one rttr-instantiated screen owning C_UISaveLoad/C_UISettings by value.

namespace wh::guimodule {

class C_UIMenu
    : public C_UIMenuBase
    , public wh::I_UIMenu
    , public Offsets::IActionListener
    , public Offsets::ISystemEventListener
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIMenu;
    // Primary-vtable overrides: Init [1] 0x18061377C, Deinit [2] 0x182BA6F74,
    // OnModuleMessage [3] 0x18085DDC0, Update [4] 0x1810C31A0, get_type [7]
    // 0x180ED549C, get_derived_info [9] 0x1819A2894.
    // IActionListener::OnAction = 0x180557658; I_UIMenu impls: see I_UIMenu.h.

    // Signal argument signatures UNVERIFIED (subscribers are 0x10 S_Delegate pairs;
    // exposed through I_UIMenu [10..15]).
    wh::shared::C_Signal<> m_signalA;        // +0x70  empty-sentinel unk_1856694A8
    wh::shared::C_Signal<> m_signalB;        // +0x80  empty-sentinel unk_1856694A8
    wh::shared::C_Signal<> m_signalC;        // +0x90  empty-sentinel unk_185665430
    bool                   m_state;          // +0xA0  gate byte returned by I_UIMenu::GetState [9]; gates OnAction forwarding
    uint8_t                _padA1[7];        // +0xA1  (+0xA0 word-zeroed by ctor)
    uint64_t               m_A8;             // +0xA8  ctor 0 (role UNVERIFIED)
    C_UISaveLoad           m_saveLoad;       // +0xB0  EMBEDDED (ctor sub_1805FF494)
    C_UISettings           m_settings;       // +0x1D8 EMBEDDED (ctor sub_180600544)
    uint64_t               m_668;            // +0x668 ctor 0 (role UNVERIFIED)
    bool                   m_670;            // +0x670 ctor 0 (role UNVERIFIED)
    uint8_t                _tail671[0x27];   // +0x671  ctor-untouched; may hold members written post-Init (UNVERIFIED)
};
static_assert(sizeof(C_UIMenu) == 0x698, "C_UIMenu must be 0x698");
static_assert(offsetof(C_UIMenu, m_signalA) == 0x70, "signals from 0x70 (ctor writes)");
static_assert(offsetof(C_UIMenu, m_saveLoad) == 0xB0, "embedded C_UISaveLoad at 0xB0");
static_assert(offsetof(C_UIMenu, m_settings) == 0x1D8, "embedded C_UISettings at 0x1D8");

}  // namespace wh::guimodule
