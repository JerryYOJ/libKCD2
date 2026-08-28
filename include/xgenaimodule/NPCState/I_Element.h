#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include "../../CryEngine/CryCommon/CryString.h"
#include "../I_AIObjectNotifyListener.h"
#include "E_ElementType.h"

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
    virtual bool unk_03();                                // [3] 0x1807DF524 unk_02()==0
    virtual int unk_04(I_Element* other);                 // [4] 0x1807DF7AC type compare
    virtual bool unk_05(I_Element* other);                // [5] 0x1807DF5EC
    virtual bool unk_06();                                // [6] 0x180838AE0 false
    virtual bool unk_07(I_Element* other);                // [7] 0x180DEFFAC type equality
    virtual bool unk_08();                                // [8] 0x180838AE0 false
    virtual I_Element* unk_09() = 0;                      // [9] clone
    virtual std::uint64_t unk_10() = 0;                   // [10] type hash
    virtual bool unk_11();                                // [11] 0x180838AE0 false
    virtual bool unk_12();                                // [12] 0x180838AE0 false
    virtual I_Element* unk_13();                          // [13] 0x1804C88CC -> [9]
    virtual I_Element* unk_14();                          // [14] 0x1804C88CC -> [9]
    virtual void unk_15(void* src);                       // [15] 0x1807E1328 copies +0x08
    virtual void unk_16();                                // [16] 0x1807DFD2C detach
    virtual bool unk_17();                                // [17] 0x180838AE0 false
    virtual void unk_18(void* out);                       // [18] 0x181AA9C40 sret 16-byte
    virtual std::int64_t unk_19();                        // [19] 0x181A72470 returns 1
    virtual bool unk_20();                                // [20] 0x18041A6A0 true
    virtual void unk_21();                                // [21] nullsub_1
    virtual bool unk_22();                                // [22] 0x18041A6A0 true
    virtual std::int64_t unk_23();                        // [23] 0x181A72470 returns 1
    virtual bool unk_24() = 0;                            // [24]
    virtual bool unk_25() = 0;                            // [25]
    virtual void unk_26();                                // [26] nullsub_1
    virtual bool unk_27();                                // [27] 0x180838AE0 false
    virtual void unk_28(void* out);                       // [28] 0x181AA9C70 sret empty string
    virtual void unk_29(std::uint64_t* arg);              // [29] callee of [0]
    RTTR_ENABLE()                                         // [30..32]

    CryStringT<char> m_unknown08;                         // +0x08 interned; id unverified
    std::uint8_t m_unknown10;                             // +0x10 mode 0/1/2; id unverified
    std::uint8_t _pad11[7];                               // +0x11
};

static_assert(offsetof(I_Element, m_unknown08) == 0x08,
              "I_Element::m_unknown08 offset mismatch");
static_assert(offsetof(I_Element, m_unknown10) == 0x10,
              "I_Element::m_unknown10 offset mismatch");
static_assert(sizeof(I_Element) == 0x18,
              "I_Element size mismatch");

}  // namespace wh::xgenaimodule::NPCState
