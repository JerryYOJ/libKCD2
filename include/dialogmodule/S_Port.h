#pragma once
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::dialogmodule::data::S_Port -- dialogue port reference record (KCD2 1.5.6, kd7u).
// sizeof 0x10.
// -----------------------------------------------
// RTTI TD 0x184B67D28; vtable 0x183AB1E68 (3 slots); ctor sub_180DD7A24; deleting-dtor
// [0] sub_181A6DAD0. Names a concept-graph port the dialogue graph binds to (resolved by
// the "Port" EE function C_FunctionPort at branch-evaluation time).

namespace wh::dialogmodule::data {

struct S_Port {
    inline static constexpr auto RTTI = Offsets::RTTI_S_Port;
    virtual ~S_Port();            // [0] deleting-dtor sub_181A6DAD0
    virtual void _vf1();          // [1] [role UNVERIFIED]
    virtual void _vf2();          // [2] [role UNVERIFIED]

    CryStringT<char> m_portRef;   // +0x08  port name/id
};
static_assert(sizeof(S_Port) == 0x10, "S_Port must be 0x10");

}  // namespace wh::dialogmodule::data
