#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <boost/container/vector.hpp>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_CombatShoutParticipant.h"

namespace wh::entitymodule {

struct S_CombatShoutContext {
    std::int32_t                                      m_hitStrength;               // +0x00
    std::int32_t                                      m_hitType;                   // +0x04
    bool                                              m_blockedAttack;             // +0x08
    bool                                              m_perfectlyBlockedAttack;    // +0x09
    bool                                              m_stealthKill;               // +0x0A
    std::uint8_t                                      _pad0B;                      // +0x0B
    float                                             m_opponentDistance;          // +0x0C
    boost::container::vector<CryStringT<char>>       m_metaroles;                 // +0x10
    std::vector<S_CombatShoutParticipant>             m_participants;              // +0x28
    float                                             m_skirmishAge;               // +0x40
    std::int32_t                                      m_skirmishActiveParticipants;// +0x44
    std::int32_t                                      m_targetOriginalMaterialId;  // +0x48
    bool                                              m_received;                  // +0x4C
    std::uint8_t                                      _pad4D[3];                   // +0x4D
};
static_assert(sizeof(S_CombatShoutContext) == 0x50);
static_assert(alignof(S_CombatShoutContext) == 0x08);
static_assert(offsetof(S_CombatShoutContext, m_hitStrength) == 0x00);
static_assert(offsetof(S_CombatShoutContext, m_opponentDistance) == 0x0C);
static_assert(offsetof(S_CombatShoutContext, m_metaroles) == 0x10);
static_assert(offsetof(S_CombatShoutContext, m_participants) == 0x28);
static_assert(offsetof(S_CombatShoutContext, m_skirmishAge) == 0x40);
static_assert(offsetof(S_CombatShoutContext, m_targetOriginalMaterialId) == 0x48);
static_assert(offsetof(S_CombatShoutContext, m_received) == 0x4C);

}  // namespace wh::entitymodule
