#pragma once
#include <cstddef>
#include <boost/container/vector.hpp>
#include "../CryEngine/CryCommon/CryString.h"
#include "../framework/WUID.h"

namespace wh::entitymodule {

struct S_CombatShoutParticipant {
    wh::framework::WUID                         m_soulWuid; // +0x00
    boost::container::vector<CryStringT<char>> m_metaroles;// +0x08, sorted unique
};
static_assert(sizeof(S_CombatShoutParticipant) == 0x20);
static_assert(offsetof(S_CombatShoutParticipant, m_soulWuid) == 0x00);
static_assert(offsetof(S_CombatShoutParticipant, m_metaroles) == 0x08);

}  // namespace wh::entitymodule
