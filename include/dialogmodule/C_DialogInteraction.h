#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::dialogmodule::C_DialogInteraction -- speaker/listener request record
// (KCD2 1.5.6, kd7u).  sizeof ~0xE8 (232) UNVERIFIED.
// -----------------------------------------------
// RTTI TD 0x184B4DF50; vtable 0x183A42510 (1 slot: deleting dtor); ctor
// sub_180614DCC(this, a2, a3, a4:byte); dtor sub_180614C80. A dialog request pairing
// two participants (a2/a3 = ids/handles copied to +0x58/+0x68). No behavior beyond the
// dtor; field roles UNVERIFIED. Pinned ctor writes: +0xC0 qword = 1, +0xC8 word = 1,
// +0xCA byte = a4. Total size approximate -- offsets asserted, sizeof not.

namespace wh::dialogmodule {

class C_DialogInteraction {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DialogInteraction;
    virtual ~C_DialogInteraction();   // [0] (only vtable slot)

    uint8_t  _unk08[0x50];            // +0x08..+0x57  [not walked]
    uint8_t  m_participantA[0x10];    // +0x58  speaker id/handle (ctor a2) [encoding UNVERIFIED]
    uint8_t  m_participantB[0x10];    // +0x68  listener id/handle (ctor a3) [encoding UNVERIFIED]
    uint8_t  _unk78[0x48];            // +0x78..+0xBF  [not walked]
    uint64_t m_qC0;                   // +0xC0  ctor 1
    uint16_t m_wC8;                   // +0xC8  ctor 1
    uint8_t  m_bCA;                   // +0xCA  ctor a4
    uint8_t  _padCB[0x1D];            // +0xCB..+0xE7  [tail size UNVERIFIED]
};
static_assert(offsetof(C_DialogInteraction, m_participantA) == 0x58);
static_assert(offsetof(C_DialogInteraction, m_qC0) == 0xC0);
// sizeof == 0xE8 by construction; total size ~0xE8 UNVERIFIED (see header note).

}  // namespace wh::dialogmodule
