#pragma once
#include <cstdint>
#include "../framework/C_Signal.h"

// -----------------------------------------------
// wh::rpgmodule::C_CombatSoul -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0xA8.
// -----------------------------------------------
// RTTI-named (vtable written by ctor sub_18070F6CC); dtor sub_18096712C. Embedded in C_Soul
// @+0xF0. Verify-confirmed anchors: exactly 7 C_Signal heads at +0x08..+0x68, owner @+0x78, two
// ref-counted smart pointers @+0x98/+0xA0 (sub_1803F2814 / sub_18117A950); subscribes mailboxes
// 522 / 279 / 96. Signal purposes and the +0x80..+0x98 interior are UNRESOLVED (flagged).

namespace wh::rpgmodule {

class C_Soul;

class C_CombatSoul {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatSoul;
    virtual ~C_CombatSoul() = default;    // slot order UNVERIFIED
    wh::shared::C_Signal<> m_signal08;    // +0x08  purpose unresolved
    wh::shared::C_Signal<> m_signal18;    // +0x18
    wh::shared::C_Signal<> m_signal28;    // +0x28
    wh::shared::C_Signal<> m_signal38;    // +0x38
    wh::shared::C_Signal<> m_signal48;    // +0x48
    wh::shared::C_Signal<> m_signal58;    // +0x58
    wh::shared::C_Signal<> m_signal68;    // +0x68
    C_Soul*  m_pOwner;                    // +0x78  back-ptr
    uint64_t m_unk80[3];                  // +0x80..+0x98  unresolved
    void*    m_pRef98;                    // +0x98  OWNED ref-counted ptr (_smart_ptr semantics; class unresolved)
    void*    m_pRefA0;                    // +0xA0  OWNED ref-counted ptr (_smart_ptr semantics; class unresolved)
};
static_assert(sizeof(C_CombatSoul) == 0xA8, "C_CombatSoul must be 0xA8");

}  // namespace wh::rpgmodule
