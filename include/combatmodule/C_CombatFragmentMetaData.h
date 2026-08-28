#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../rttr/rttr_enable.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "C_CombatHitInfo.h"

namespace wh::combatmodule {

class C_CombatFragmentMetaData {
public:
    RTTR_ENABLE()                                         // [0..2]
    CryGUID m_guid;                                       // +0x08 RTTR "GUID"
    std::uint32_t m_animDatabaseId;                       // +0x18 RTTR "AnimDatabaseId"
    bool m_obstacleTestEnabled;                           // +0x1C RTTR "ObstacleTestEnabled"
    std::uint8_t _pad1D[3];                               // +0x1D
    std::vector<C_CombatHitInfo> m_hits;                  // +0x20 RTTR "Hits"
};

static_assert(offsetof(C_CombatFragmentMetaData, m_guid) == 0x08,
              "C_CombatFragmentMetaData::m_guid offset mismatch");
static_assert(offsetof(C_CombatFragmentMetaData, m_hits) == 0x20,
              "C_CombatFragmentMetaData::m_hits offset mismatch");
static_assert(sizeof(C_CombatFragmentMetaData) == 0x38,
              "C_CombatFragmentMetaData size mismatch");

}  // namespace wh::combatmodule
