#pragma once
#include <cstdint>
#include "C_CombatAutomationAction.h"

// -----------------------------------------------
// wh::combatmodule::C_CombatAutomationDefense : C_CombatAutomationAction -- KCD2 1.5.6 (kd7u).  sizeof 0x50.
// -----------------------------------------------
// Embedded by value at C_CombatAutomation+0x118 (ctor sub_1810EF244; vtable 0x183B0A390; debug
// dump sub_1827683BC "DEF %s: #%d, NO/NB/PB/MS/Dodge/MoveRes"). The evaluate path (sub_180C56048)
// computes cumulative reaction weights, rolls m_rngState, and picks action 0/5/6/7/8.
// NOTE: this leaf uses the inherited base slot +0x28 (m_field28) as a lazy cached director pointer
// (sub_1807302CC reads/caches it).

namespace wh::combatmodule {

// Reaction weight override (5 floats, heap 20B; per-float < 0 = "no override"). Field names from
// the debug dump order (NoReaction/Block/PerfectBlock/MasterStrike/Dodge).
struct S_ReactionWeights {
    float noReaction;     // +0x00
    float block;          // +0x04
    float perfectBlock;   // +0x08
    float masterStrike;   // +0x0C
    float dodge;          // +0x10
};
static_assert(sizeof(S_ReactionWeights) == 0x14, "S_ReactionWeights must be 0x14");

class C_CombatAutomationDefense : public C_CombatAutomationAction {
public:
    const char* GetName() const override { return "AutomationDefense"; }   // [3] 0x181A7E1B0
    int GetActionKind() const override { return 4; }                       // [10] 0x181A72500

    uint64_t m_field30;                    // +0x30  (ctor 0; no reader in ANY Defense method -- reserved/unused)
    S_ReactionWeights* m_pWeightOverride;  // +0x38  OWNED heap 20B; null = none (writer beyond ctor not located)
    uint64_t m_rngState;                   // +0x40  LCG state (reaction roll)
    bool     m_bUseBlockQueryModifier;     // +0x48  gates the extra weight modifier (sub_182766C10)
    uint8_t  _pad49[7];                    // +0x49
};
static_assert(sizeof(C_CombatAutomationDefense) == 0x50, "C_CombatAutomationDefense must be 0x50");

}  // namespace wh::combatmodule
