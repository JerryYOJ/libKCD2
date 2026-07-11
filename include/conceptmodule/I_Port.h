#pragma once
#include <cstdint>
#include "C_SharedResource.h"
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::conceptmodule::I_Port -- node-graph port base (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// Despite the I_ prefix this carries data (its vftable is written by the port ctor chain
// sub_1806B28F0): C_SharedResource init, then +0x10 = -1, +0x14 = 0, +0x18/+0x20 = null,
// +0x28 = empty CryString (port name).  C_PortRef derives it at +0x30.

namespace wh::conceptmodule {

class I_Port : public C_SharedResource {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_Port;
    int32_t  m_param10;        // +0x10  ctor -1 [role UNVERIFIED -- port index candidate]
    uint8_t  m_flag14;         // +0x14  ctor 0 [role UNVERIFIED]
    uint8_t  _pad15[3];        // +0x15
    uint64_t m_unk18;          // +0x18  ctor 0; NOT touched by dtor sub_1806B28B8 -> non-owning field (raw back-ptr or scalar); type unresolved
    void*    m_unk20;          // +0x20  OWNED _smart_ptr<T> (intrusive refcount); dtor sub_1806B28B8 releases via sub_1804F6588 (vtbl[0]=destroy, strong@+8 / weak@+0xC) when non-null; pointee T unresolved
    CryStringT<char> m_name;   // +0x28
};
static_assert(sizeof(I_Port) == 0x30, "I_Port must be 0x30 (C_PortRef member at +0x30)");

}  // namespace wh::conceptmodule
