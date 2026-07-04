#pragma once
#include <cstdint>
#include "C_SharedResource.h"
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::conceptmodule::C_Node -- node-graph node base (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// Ctor sub_1806B2744: C_SharedResource init, then name (empty CryString), +0x18 = 1,
// +0x1C = -1, +0x20 = 0, +0x28/+0x30/+0x38 zeroed.  sizeof 0x40 (PROVEN: derived
// conceptmodule::C_Effect places its first member at +0x40 and C_AutoTriggerable adds no data).
// rttr-reflected (constructor_wrapper/property_wrapper TDs); nodes are what the concept graph
// wires together via I_Port/C_PortRef.

namespace wh::conceptmodule {

class C_Node : public C_SharedResource {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Node;
    CryStringT<char> m_name;   // +0x10
    int32_t  m_param18;        // +0x18  ctor 1 [role UNVERIFIED]
    int32_t  m_param1C;        // +0x1C  ctor -1 [role UNVERIFIED]
    uint8_t  m_flag20;         // +0x20  ctor 0 [role UNVERIFIED]
    uint8_t  _pad21[7];        // +0x21
    uint64_t m_unk28;          // +0x28  ctor 0 [role UNVERIFIED]
    uint64_t m_unk30;          // +0x30  ctor 0 [role UNVERIFIED]
    uint64_t m_unk38;          // +0x38  ctor 0 [role UNVERIFIED]
};
static_assert(sizeof(C_Node) == 0x40, "C_Node must be 0x40 (derived members start at +0x40)");

}  // namespace wh::conceptmodule
