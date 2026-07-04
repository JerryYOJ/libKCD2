#pragma once
#include <cstdint>
#include "guimodule/C_UIExtendedInfo.h"
#include "framework/C_Signal.h"

// -----------------------------------------------
// wh::guimodule::C_UIApseCharacterContent -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x200.
// -----------------------------------------------
// RTTI .?AVC_UIApseCharacterContent@guimodule@wh@@ (TD 0x184C91EB8). ctor sub_180BC7EA0.
// Bases: C_UIExtendedInfo @+0x00 (-> C_UIFlashBase -> C_UIBase) + IUIElementEventListener
// @+0x10 + IHardwareMouseEventListener @+0x58 (same shape as C_UIExtendedInfo).
// vtables: primary 0x183A81770 (19 slots = C_UIExtendedInfo shape, NO additions;
// overrides [1] Init 0x180ED227C, [2] Deinit 0x182B12354, [4] Update 0x180567FBC,
// [10] SetVisible 0x180562A2C), hw-mouse 0x183A81058 ([1] 0x181179340).
//
// The character-paperdoll content pane, flash element "ApseCharacter"
// (C_UIExtendedInfo ctor sub_180BC8628(this, "ApseCharacter")). Embedded BY VALUE in
// C_UICharacterBase @+0x1C8 (size pinned by the base's next member block @+0x3C8).
// Own member roles beyond the signal UNVERIFIED.

namespace wh::guimodule {

class C_UIApseCharacterContent : public C_UIExtendedInfo {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIApseCharacterContent;
    wh::shared::C_Signal<> m_signalD8;    // +0xD8  delegate table &unk_185669278 [signature UNVERIFIED]
    uint8_t  _unkE8[0x108];               // +0xE8..+0x1F0  ctor zero-writes at +0x120/+0x160/+0x1A0/+0x1E0 (qwords) and +0x1E8 (byte); roles UNVERIFIED
    void*    m_listSentinel1F0;           // +0x1F0  self-ref list/map head (ctor alloc) [container type UNVERIFIED]
    uint64_t m_unk1F8;                    // +0x1F8  ctor 0
};
static_assert(sizeof(C_UIApseCharacterContent) == 0x200, "C_UIApseCharacterContent must be 0x200");
static_assert(offsetof(C_UIApseCharacterContent, m_signalD8) == 0xD8, "signal at 0xD8");

}  // namespace wh::guimodule
