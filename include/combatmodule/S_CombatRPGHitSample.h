#pragma once
#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace wh::combatmodule {

struct S_CombatRPGHitSample {
    std::int32_t m_bodySubpartId; // +0x00, default -1
    float        m_attackCoef;    // +0x04, negative becomes 1.0
    float        m_attackEnergy;  // +0x08
    std::int32_t m_hitIndex;      // +0x0C, zero marks the first hit
};
static_assert(sizeof(S_CombatRPGHitSample) == 0x10);
static_assert(alignof(S_CombatRPGHitSample) == 0x04);
static_assert(offsetof(S_CombatRPGHitSample, m_bodySubpartId) == 0x00);
static_assert(offsetof(S_CombatRPGHitSample, m_attackCoef) == 0x04);
static_assert(offsetof(S_CombatRPGHitSample, m_attackEnergy) == 0x08);
static_assert(offsetof(S_CombatRPGHitSample, m_hitIndex) == 0x0C);
static_assert(std::is_trivially_copyable_v<S_CombatRPGHitSample>);

}  // namespace wh::combatmodule
