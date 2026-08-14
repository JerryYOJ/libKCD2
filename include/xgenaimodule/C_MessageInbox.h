#pragma once
#include <cstdint>
#include <vector>
#include "S_MessageInboxEntry.h"

// -----------------------------------------------
// wh::xgenaimodule::C_MessageInbox -- configured AI message queue (KCD2 WHGame.dll
// 1.5.6, kd7u).  sizeof 0x48 (all observed allocations use 0x48; configuration
// helper sub_18041A114 writes the final field at +0x40).
// -----------------------------------------------
// RTTI TD rva 0x4F5D5C0; vtable 0x183A37DB0, 1 slot. Real base chain (template
// callback machinery, SCRIPTABLE batch -- modeled flat here):
//   C_MessageInbox : Callbacks::C_PlainCallbackExtension : C_NoDataExtension<Functor0>
//   with C_CallbackListHolder @+0x08 and C_TrackSequencing<1> @+0x10.
// Real ctor sub_180419D58; configuration helper sub_18041A114 assigns the name,
// key, mode, and message-handle entries. Brain-template materialization creates
// inboxes separately from the C_AIBrain pointer installed on C_IntelligentObject.

namespace wh::xgenaimodule {

class C_MessageInbox {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_MessageInbox;
    virtual ~C_MessageInbox();     // [0] sub_18041B258 [U -- single slot; dtor vs callback-execute unresolved]

    uint64_t    m_callbackHead;    // +0x08  C_CallbackListHolder list head, ctor: 0
    uint8_t     m_trackSeq;        // +0x10  C_TrackSequencing<1> flag, ctor: 0
    uint8_t     _pad11[7];         // +0x11
    CryStringT<char> m_str18;      // +0x18  CryStringT<char>, ctor inits empty (data = empty-string static + 12); dtor decrefs (ptr-12)
    int32_t     m_dword20;         // +0x20  ctor: -1 [U role]
    int32_t     m_dword24;         // +0x24  ctor: 0 [U role]
    std::vector<S_MessageInboxEntry> m_entries; // +0x28
    int32_t       m_mode;             // +0x40, configured as 1 or 2 in observed paths; exact enum OPEN
    uint8_t       _pad44[4];          // +0x44
};
static_assert(sizeof(C_MessageInbox) == 0x48, "C_MessageInbox must be 0x48");

}  // namespace wh::xgenaimodule
