#pragma once
#include <cstdint>
#include <vector>
#include "../conceptmodule/C_SoulEffect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"

// -----------------------------------------------
// wh::rpgmodule::C_BuffEffect -- concept-graph node applying a buff to souls
// (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI TD 0x184D09D58  vtable 0x183F0C730.  sizeof 0x148 (PROVEN: rttr constructor_wrapper
// factory sub_181183938 operator new(328) + memset 0).  Chain: conceptmodule::C_SoulEffect ->
// C_Effect -> C_AutoTriggerable<C_Node> -> C_Node -> C_SharedResource (NOT the rpgmodule
// C_Effect system).  Ctor sub_1811839F0: souls array-port @+0x88, buff-id port @+0xC8,
// float 1.0 @+0x108, then an unordered_map-shaped hash @+0x110 (sentinel list node, 16-entry
// bucket vector fill sub_181E11900, mask 7, maxidx 8).  rttr-exposed ports: "souls" vector
// port and a S_BuffDefinitionId port (property_wrapper TDs).

namespace wh::rpgmodule {

class I_Soul;
struct S_BuffDefinitionId;   // not yet RE'd (port payload type only)

class C_BuffEffect : public conceptmodule::C_SoulEffect {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_BuffEffect;
    conceptmodule::C_TypedArrayPortRef<std::vector<I_Soul*>> m_soulsPort;   // +0x88
    conceptmodule::C_TypedPortRef<S_BuffDefinitionId> m_buffIdPort;         // +0xC8
    float    m_param108;      // +0x108  ctor 1.0f [role UNVERIFIED -- strength/duration factor candidate]
    uint32_t _pad10C;         // +0x10C
    // unordered_map-shaped hash (MSVC _Hash): [key/value types UNVERIFIED]
    void*    m_mapListHead;   // +0x110  -> 32-byte self-linked sentinel node
    uint64_t m_mapSize;       // +0x118
    void*    m_mapVecBegin;   // +0x120  bucket vector (16 entries filled with the sentinel)
    void*    m_mapVecEnd;     // +0x128
    void*    m_mapVecCap;     // +0x130
    uint64_t m_mapMask;       // +0x138  ctor 7
    uint64_t m_mapMaxidx;     // +0x140  ctor 8
};
static_assert(sizeof(C_BuffEffect) == 0x148, "C_BuffEffect must be 0x148 (operator new(328))");

}  // namespace wh::rpgmodule
