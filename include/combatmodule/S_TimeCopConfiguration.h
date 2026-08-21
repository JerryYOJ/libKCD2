#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::combatmodule {

class C_CombatActor;

struct S_TimeCopConfiguration {
    float          m_phase0Time;                 // +0x00, default -infinity
    float          m_phase1Time;                 // +0x04, default -infinity
    float          m_phase2Time;                 // +0x08, default -infinity
    float          m_minSpeedBias;               // +0x0C, default 0
    float          m_maxSpeedBias;               // +0x10, default 1
    bool           m_forceUnitSpeedBias;         // +0x14
    bool           m_applyBlockSpeedModifier;    // +0x15
    bool           m_resetElapsed;               // +0x16, default true
    std::uint8_t   _pad17;                       // +0x17
    C_CombatActor* m_pPartnerOverride;           // +0x18, borrowed
};
static_assert(sizeof(S_TimeCopConfiguration) == 0x20);
static_assert(offsetof(S_TimeCopConfiguration, m_phase0Time) == 0x00);
static_assert(offsetof(S_TimeCopConfiguration, m_minSpeedBias) == 0x0C);
static_assert(offsetof(S_TimeCopConfiguration, m_pPartnerOverride) == 0x18);

}  // namespace wh::combatmodule
