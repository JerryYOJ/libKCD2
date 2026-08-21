#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::playermodule::E_InputDeviceClass -- KCD2 WHGame.dll 1.5.6 (kd7u).
// -----------------------------------------------
// Last-used input device class. Stored as a uint32 discriminant that is ALSO
// bit-tested: values are 1/2/4/16 (not a dense 0..N enum).
//
// Writers:
//   C_UIActionHintManager::OnInputEvent 0x1811671E4 (IInputEventListener [0]):
//     SInputEvent+0x00 device byte 0 or 1          -> KeyboardMouse (1)
//     device byte 4, key-name[0] != 'p' (112)      -> XboxPad (2)
//     device byte 4, key-name[0] == 'p'            -> PsPadP (16)  (ps_* keys)
//   C_Keybinds change/conflict notifiers 0x182E18A10 / 0x182E188DC:
//     E_KeybindController::Keyboard -> 1, XboxPad -> 2, Ps4Pad -> 4
//   wh_ui_InputDevice CVar (setup 0x180C3C314) accepts the set {1,2,4,16}
//     via _bittest(0x10016, value).
//
// Lockpicking formula 0x180896CAC (`and esi, 16h`) treats any of {2,4,16} as
// "controller" and loads the ControllerLockPickingTolerance* S_Constants block.

namespace wh::playermodule {

struct E_InputDeviceClass {
    enum Type : uint32_t {
        None          = 0,
        KeyboardMouse = 1,    // KB/M
        XboxPad       = 2,    // XInput / xboxpad
        PsPad         = 4,    // E_KeybindController::Ps4Pad bitflag
        PsPadP        = 16,   // hint-manager PS encoding (key name starts with 'p')
        ControllerMask = XboxPad | PsPad | PsPadP,  // 0x16
    };
};

inline bool IsController(E_InputDeviceClass::Type device)
{
    return (device & E_InputDeviceClass::ControllerMask) != 0;
}

}  // namespace wh::playermodule
