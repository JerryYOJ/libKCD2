#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::dialogmodule::data::C_DialogueProp -- dialogue prop record (KCD2 1.5.6, kd7u).
// sizeof 0x28.
// -----------------------------------------------
// RTTI TD 0x184B6F228; vtable 0x183B764C8 (3 slots); ctor sub_1813C7024; deleting-dtor
// [0] sub_180EC3B50. A prop used during a conversation (bound by the C_*PropCommand
// timeline commands). Field roles UNVERIFIED.

namespace wh::dialogmodule::data {

class C_DialogueProp {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DialogueProp;
    virtual ~C_DialogueProp();   // [0] deleting-dtor sub_180EC3B50
    virtual void _vf1();         // [1] [role UNVERIFIED]
    virtual void _vf2();         // [2] [role UNVERIFIED]

    CryStringT<char> m_arr08;    // +0x08  COW array [role UNVERIFIED]
    uint8_t  m_b10;              // +0x10  [role UNVERIFIED]
    uint8_t  _pad11[7];          // +0x11
    uint64_t _q18;               // +0x18  [not walked]
    uint64_t _q20;               // +0x20  [not walked]
};
static_assert(sizeof(C_DialogueProp) == 0x28, "C_DialogueProp must be 0x28");

}  // namespace wh::dialogmodule::data
