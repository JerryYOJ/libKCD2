#pragma once

#include "IActionListener.h"

// -----------------------------------------------
// IActionMapManager -- KCD2 CActionMapManager primary interface, PARTIAL.
// -----------------------------------------------
// Target: WHGame.dll 1.5.6 (kd7u). Completes the global-namespace forward
// declaration in crysystem/CCryAction.h (member m_pActionMapManager at
// CCryAction+0x530, accessor slot [28] 0x1803F7B00 -- both VERIFIED there).
//
// Provenance: read-only IDA trace analysis/MCM/dispatch_trace/keypath.md
// (2026-08-30):
//   [10] (vf+0x50) AddExtraActionListener 0x180562E20 -- registration site
//        0x180C3D4FA (C_UIHudHints::Init registering C_ActionHintManager+8).
//        With a null map name the listener is appended to the GLOBAL
//        C_Listeners vector at CActionMapManager+24 and receives EVERY
//        dispatched action of every ENABLED actionmap. This is the exact
//        route vanilla menu keys (C_UIMenu+0x60 -> Flash "SetInput",
//        registered 0x180C04DF2) and APSE map keys (C_UIMap+16, 0x1808BFF64)
//        ride; no helpbar hint row is consulted anywhere on it.
//   Broadcast 0x1820E0DC0 (inside dispatch vf[+0x60] 0x1808E582C) calls
//   listener vf[1](this, ActionId*, activationMode) -- the
//   Offsets::IActionListener shape. activationMode: eAAM_OnPress = 1
//   (profile rows onPress="1"; fire path passes *(action+0xF8), 0x1808E51D5).
// Unnamed _vfN slots are real functions whose role is UNVERIFIED -- do not
// call.

struct IActionMapManager {
    virtual void _vf0() = 0;   // [0]
    virtual void _vf1() = 0;   // [1]
    virtual void _vf2() = 0;   // [2]
    virtual void _vf3() = 0;   // [3]
    virtual void _vf4() = 0;   // [4]
    virtual void _vf5() = 0;   // [5]
    virtual void _vf6() = 0;   // [6]
    virtual void _vf7() = 0;   // [7]
    virtual void _vf8() = 0;   // [8]
    virtual void _vf9() = 0;   // [9]
    virtual void AddExtraActionListener(Offsets::IActionListener* pListener,
                                        const char* actionMap = nullptr) = 0;  // [10] 0x180562E20 (null = global list)
};
