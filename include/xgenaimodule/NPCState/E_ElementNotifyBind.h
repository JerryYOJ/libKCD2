#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::NPCState::E_ElementNotifyBind -- I_Element notify-registration
// mode (KCD2 WHGame.dll Steam 1.5.6). [INFERRED] Slot 27 return / +0x10 store width.
// -----------------------------------------------
// Consumed by Activate/Deactivate (slots 15/16): 1 = name-keyed map at
// C_AIObjectManager+0xC8, 2 = pointer list (C_ItemSetAsideElement 0x181A74A40).

namespace wh::xgenaimodule::NPCState {

enum E_ElementNotifyBind : std::uint8_t {
    None      = 0,  // false stub 0x180838AE0
    ByName    = 1,  // true stub 0x18041A6A0
    ByPointer = 2,  // C_ItemSetAsideElement 0x181A74A40
};

}  // namespace wh::xgenaimodule::NPCState
