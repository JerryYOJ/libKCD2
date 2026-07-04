#pragma once
#include <cstdint>
#include <vector>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "S_FactionDefinitionID.h"

// -----------------------------------------------
// wh::rpgmodule::C_TemporaryFactionEffect -- concept-graph node temporarily switching souls'
// faction (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI TD 0x184D09C38  vtable 0x183B4AFA8.  sizeof 0x120 (PROVEN: rttr constructor_wrapper
// factory sub_1812A0F70 operator new(288)).  Chain: conceptmodule::C_Effect ->
// C_AutoTriggerable<C_Node> -> C_Node -> C_SharedResource (derives C_Effect directly, no
// C_SoulEffect layer).  Ctor sub_1812A100C: souls array-port @+0x88, faction-id port @+0xC8,
// three zeroed qwords @+0x108.

namespace wh::rpgmodule {

class I_Soul;

class C_TemporaryFactionEffect : public conceptmodule::C_Effect {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_TemporaryFactionEffect;
    conceptmodule::C_TypedArrayPortRef<std::vector<I_Soul*>> m_soulsPort;    // +0x88
    conceptmodule::C_TypedPortRef<S_FactionDefinitionID> m_factionIdPort;    // +0xC8
    uint64_t m_unk108;   // +0x108  ctor 0 } vector-shaped triple
    uint64_t m_unk110;   // +0x110  ctor 0 } [std::vector INFERRED, element type unknown]
    uint64_t m_unk118;   // +0x118  ctor 0 }
};
static_assert(sizeof(C_TemporaryFactionEffect) == 0x120,
              "C_TemporaryFactionEffect must be 0x120 (operator new(288))");

}  // namespace wh::rpgmodule
