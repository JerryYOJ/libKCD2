#pragma once
#include <cstddef>
#include <cstdint>
#include "E_LockPickingState.h"

namespace Offsets { struct IUIElement; }

// -----------------------------------------------
// wh::playermodule::C_LockPickingView -- Flash "uilockpicking" owner
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x28.
// -----------------------------------------------
// RTTI .?AVC_LockPickingView@playermodule@wh@@ (TD 0x184DF9DC8).
// vtable 0x183C096F0, 2 slots. Alloc 0x28 in C_LockPicking ctor; stored at
// C_LockPicking+0x130. ctor sub_18168DA98(this, &session->m_state).
// dtor sub_181744C9C unloads "uilockpicking" from IFlashUI.

namespace wh::playermodule {

class C_LockPickingView {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_LockPickingView;
    virtual void OnElementEvent(const char** name, char visible); // [0] 0x182E8ED78
    virtual ~C_LockPickingView();                                 // [1] 0x1817448D8

    E_LockPickingState::Type* m_pState;   // +0x08  &C_LockPicking::m_state
    Offsets::IUIElement*      m_pElement; // +0x10  Flash "LockPicking"
    const char*               m_pContext; // +0x18  "lockpicking"
    uint8_t                   m_flag20;   // +0x20
    uint8_t                   _pad21[7];  // +0x21
};
static_assert(sizeof(C_LockPickingView) == 0x28,
              "C_LockPickingView must match the 0x28 ctor allocation");
static_assert(offsetof(C_LockPickingView, m_pState) == 0x08,
              "view state pointer must be at +0x08");
static_assert(offsetof(C_LockPickingView, m_pElement) == 0x10,
              "Flash element must be at +0x10");

}  // namespace wh::playermodule
