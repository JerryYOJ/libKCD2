#pragma once
#include <cstdint>
#include <set>
#include <tuple>
#include "E_CombatInputClass.h"
#include "E_CombatActionType.h"
#include "E_CombatAttackType.h"
#include "E_CombatZoneId.h"

namespace wh::combatmodule {

struct S_RestrictedInputClass {
    E_CombatInputClass m_inputClass; // +0x00
    E_CombatActionType m_actionType; // +0x04
    E_CombatAttackType m_attackType; // +0x08
    std::uint32_t      _pad0C;       // +0x0C
    std::set<E_CombatZoneId> m_zones;// +0x10

    bool operator<(const S_RestrictedInputClass& rhs) const {
        return std::tie(m_inputClass, m_actionType, m_attackType)
             < std::tie(rhs.m_inputClass, rhs.m_actionType, rhs.m_attackType);
    }
};
static_assert(sizeof(S_RestrictedInputClass) == 0x20);
static_assert(offsetof(S_RestrictedInputClass, m_zones) == 0x10);

}  // namespace wh::combatmodule
