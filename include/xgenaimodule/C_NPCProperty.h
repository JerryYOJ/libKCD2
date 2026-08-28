#pragma once
#include "../framework/C_ModelProperty.h"
#include "I_NPC.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_NPCProperty : wh::shared::C_ModelProperty<I_NPC*, ...>
// (KCD2 WHGame.dll 1.5.6). sizeof 0x40. 6 slots (4 inherited + 2 own).
// -----------------------------------------------
// RTTI .?AVC_NPCProperty@activitysystem@xgenaimodule@wh@@
// vtable 0x183A821E0, COL 0x1840DE178 offset 0, CHD 0x18455FB10 nbase=3.
// ctor 0x180BCA684, deleting dtor 0x1832F80BC.
// Parent wh::shared::C_ModelProperty<I_NPC*, C_StandardDefaultValueTrait<I_NPC*>,
// C_SignalWithNewValueTrait<I_NPC*>, C_DebugNoTrace, C_NoSaveLoad, C_OwnershipEmpty> vt 0x183A821B8.
//
// A model-property specialization that auto Bind/Unbinds the referenced I_NPC (vf+0x1E8 /
// vf+0x1F0 on the NPC, callback token {this, 0x1819EDA60}) on every value change, and broadcasts
// a second (old,new) signal beyond the base's new-value-only one. Setter (non-virtual helper)
// 0x180A19FB8(this, I_NPC*): if changed -> Unbind -> store +0x08 -> emit m_value's signal ->
// emit m_onOldNew -> Bind.

namespace wh::xgenaimodule::activitysystem {

class C_NPCProperty : public wh::shared::C_ModelProperty<
    wh::xgenaimodule::I_NPC*,
    wh::shared::traits::C_StandardDefaultValueTrait<wh::xgenaimodule::I_NPC*>,
    wh::shared::traits::C_SignalWithNewValueTrait<wh::xgenaimodule::I_NPC*>,
    wh::shared::traits::C_DebugNoTrace,
    wh::shared::traits::C_NoSaveLoad,
    wh::shared::traits::C_OwnershipEmpty> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_NPCProperty;

    virtual void Bind();    // [4] 0x180A1A050  if m_value: NPC vf+0x1E8({this, 0x1819EDA60})
    virtual void Unbind();  // [5] 0x180A1A01C  NPC vf+0x1F0({this, 0x1819EDA60})

    wh::shared::C_Signal<wh::xgenaimodule::I_NPC*, wh::xgenaimodule::I_NPC*> m_onOldNew;  // +0x30  own addition vs parent; empty sentinel 0x18566C050
};
static_assert(sizeof(C_NPCProperty) == 0x40, "C_NPCProperty must be 0x40");
static_assert(offsetof(C_NPCProperty, m_onOldNew) == 0x30, "m_onOldNew at +0x30");

}  // namespace wh::xgenaimodule::activitysystem
