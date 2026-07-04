#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::C_MessageInbox -- per-object AI message queue (KCD2 WHGame.dll
// 1.5.6, kd7u).  sizeof 0x40 (ctor-proven; the ONLY genuine ascending-init ctor
// found in the G2 sweep).
// -----------------------------------------------
// RTTI TD rva 0x4F5D5C0; vtable 0x183A37DB0, 1 slot. Real base chain (template
// callback machinery, SCRIPTABLE batch -- modeled flat here):
//   C_MessageInbox : Callbacks::C_PlainCallbackExtension : C_NoDataExtension<Functor0>
//   with C_CallbackListHolder @+0x08 and C_TrackSequencing<1> @+0x10.
// Real ctor sub_180419D58. Creators: sub_180419AA8(endpoint, npc, flag, u)
// (get-or-create) and sub_18041990C. The NPC factory resolves the endpoint by entity
// GUID in q_185493118 (fallback default endpoint q_185493120), then attaches the
// inbox to the NPC via spine slot [21] SetMessageInbox (G2_supplement §3.11).

namespace wh::xgenaimodule {

class C_MessageInbox {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_MessageInbox;
    virtual ~C_MessageInbox();     // [0] sub_18041B258 [U -- single slot; dtor vs callback-execute unresolved]

    uint64_t    m_callbackHead;    // +0x08  C_CallbackListHolder list head, ctor: 0
    uint8_t     m_trackSeq;        // +0x10  C_TrackSequencing<1> flag, ctor: 0
    uint8_t     _pad11[7];         // +0x11
    const void* m_tickCounter;     // +0x18  = sub_1804FD80C()+3 (frame/tick counter ptr idiom)
    int32_t     m_dword20;         // +0x20  ctor: -1 [U role]
    int32_t     m_dword24;         // +0x24  ctor: 0 [U role]
    uint64_t    m_unk28;           // +0x28  ctor: 0 [U role]
    uint64_t    m_unk30;           // +0x30  ctor: 0 [U role]
    uint64_t    m_unk38;           // +0x38  ctor: 0 [U role]
};
static_assert(sizeof(C_MessageInbox) == 0x40, "C_MessageInbox must be 0x40");

}  // namespace wh::xgenaimodule
