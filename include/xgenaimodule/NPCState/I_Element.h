#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include "../../CryEngine/CryCommon/CryString.h"
#include "../I_AIObjectNotifyListener.h"
#include "E_ElementType.h"
#include "E_ElementNotifyBind.h"
#include "S_ElementKey.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::I_Element -- NPC-state element interface
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x18; vtable 0x183A50390 (33 slots).
// -----------------------------------------------
// MSVC CHD 0x184503BD8: private I_AIObjectNotifyListener at mdisp=0
// (BCD attributes 0x4D). RTTR base builder is empty; RTTR_ENABLE() takes no
// args. Slot 2 returns E_ElementType (C_CombatAutomationsElement writes 0x13).
// Slot names other than the RTTR trio are not encoded.

namespace wh::xgenaimodule::NPCState {

class I_Element : private wh::xgenaimodule::I_AIObjectNotifyListener {
public:
    virtual ~I_Element();                                 // [1] 0x18172E148
    virtual E_ElementType::Type unk_02() = 0;             // [2] element type
    virtual bool Equals(const I_Element* other) const; // [3] 0x1807DF524 unk_02()==0
    virtual int Compare(const I_Element* other) const; // [4] 0x1807DF7AC type compare
    virtual bool Matches(const I_Element* other) const; // [5] 0x1807DF5EC
    virtual bool unk_06(const I_Element* other) const; // [6] 0x180838AE0 false
    virtual bool HasSameType(const I_Element* other) const; // [7] 0x180DEFFAC type equality
    virtual bool IsEmpty() const; // [8] 0x180838AE0 false
    virtual I_Element* Clone() const = 0; // [9] clone
    virtual std::uint64_t GetHash() const = 0; // [10] type hash
    virtual bool unk_11() const; // [11] 0x180838AE0 false
    virtual bool unk_12() const; // [12] 0x180838AE0 false
    virtual I_Element* CloneAsElement() const; // [13] 0x1804C88CC -> [9]
    virtual I_Element* CreateRequired() const; // [14] 0x1804C88CC -> [9]
    virtual void Activate(const CryStringT<char>& npcName); // [15] 0x1807E1328 copies +0x08
    virtual void Deactivate(); // [16] 0x1807DFD2C detach
    virtual bool MatchesHandContent(const I_Element* other) const; // [17] 0x180838AE0 false
    virtual S_ElementKey GetKey() const; // [18] 0x181AA9C40 sret 16-byte
    virtual int unk_19(void* context, void* source); // [19] 0x181A72470 returns 1; pointee types OPEN
    virtual bool unk_20(/*context*/); // [20] 0x18041A6A0 true
    virtual void unk_21(/*context*/); // [21] nullsub_1
    virtual bool unk_22() const; // [22] 0x18041A6A0 true
    virtual std::int32_t unk_23() const; // [23] 0x181A72470 returns 1
    virtual bool WritePayload(void* writer) const = 0; // [24]
    virtual bool ReadPayload(void* reader, void* ctxA, void* ctxB, bool* ok) = 0; // [25]
    virtual void unk_26(void* actor, void* fragments, void* ctx); // [26] nullsub_1; pointee types OPEN
    virtual E_ElementNotifyBind GetNotifyBind() const; // [27] 0x180838AE0 false
    virtual CryStringT<char> GetNotifyName() const; // [28] 0x181AA9C70 sret empty string
    virtual void OnAIObjectNotify(CryStringT<char>* id); // [29] callee of [0]
    RTTR_ENABLE()                                         // [30..32]

    CryStringT<char> m_npcName; // +0x08 interned; id unverified
    E_ElementNotifyBind m_notifyBind; // +0x10 mode 0/1/2; id unverified
    std::uint8_t _pad11[7]; // +0x11
};

static_assert(offsetof(I_Element, m_npcName) == 0x08,
              "I_Element::m_npcName offset mismatch");
static_assert(offsetof(I_Element, m_notifyBind) == 0x10,
              "I_Element::m_notifyBind offset mismatch");
static_assert(sizeof(I_Element) == 0x18,
              "I_Element size mismatch");

}  // namespace wh::xgenaimodule::NPCState
