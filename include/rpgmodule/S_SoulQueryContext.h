#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::S_SoulQueryContext -- contextual inputs for soul-property
// evaluation (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x28.
// -----------------------------------------------
// CreateSoulQueryContext (0x1808292A0) and its RTTR parameter metadata prove
// the first four fields and names. Modifier readers use QueryReason at +0x18.
// The final zero-initialized qword has no recovered semantic role and remains
// explicitly unresolved.

namespace wh::entitymodule {
class C_Item;
}

namespace wh::rpgmodule {

class I_Soul;

struct S_SoulQueryContext {
    enum class E_QueryReason : std::int32_t {
        Default            = 0,
        BaseValueQuery     = 1,
        LongTermValueQuery = 2,
        DialogSkillCheck   = 3,
        Haggle             = 4,
        Combat             = 5,
        Reward             = 6,
    };

    I_Soul* m_opponent;                        // +0x00 factory parameter "Opponent"
    entitymodule::C_Item* m_opponentItem;      // +0x08 factory parameter "OpponentItem"
    entitymodule::C_Item* m_soulItem;          // +0x10 factory parameter "SoulItem"
    E_QueryReason m_queryReason;               // +0x18 factory parameter "QueryReason"
    std::uint8_t _pad1C[4];                   // +0x1C
    std::uint64_t m_unknown20;                 // +0x20 zero-initialized; role unresolved
};

static_assert(sizeof(S_SoulQueryContext::E_QueryReason) == 4,
              "S_SoulQueryContext::E_QueryReason size mismatch");
static_assert(offsetof(S_SoulQueryContext, m_opponent) == 0x00,
              "S_SoulQueryContext::m_opponent offset mismatch");
static_assert(offsetof(S_SoulQueryContext, m_opponentItem) == 0x08,
              "S_SoulQueryContext::m_opponentItem offset mismatch");
static_assert(offsetof(S_SoulQueryContext, m_soulItem) == 0x10,
              "S_SoulQueryContext::m_soulItem offset mismatch");
static_assert(offsetof(S_SoulQueryContext, m_queryReason) == 0x18,
              "S_SoulQueryContext::m_queryReason offset mismatch");
static_assert(offsetof(S_SoulQueryContext, m_unknown20) == 0x20,
              "S_SoulQueryContext::m_unknown20 offset mismatch");
static_assert(sizeof(S_SoulQueryContext) == 0x28,
              "S_SoulQueryContext size mismatch");

}  // namespace wh::rpgmodule
