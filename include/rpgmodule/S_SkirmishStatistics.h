#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::rpgmodule {

struct S_SkirmishStatistics {
    virtual ~S_SkirmishStatistics();                        // [0] 0x1814AF5F8
    RTTR_ENABLE()                                             // [1..3]

    int m_friends;                                           // +0x08 RTTR "Friends"
    int m_unknown0C;                                         // +0x0C duplicate labels
    int m_enemies;                                           // +0x10 RTTR "Enemies"
    int m_unknown14;                                         // +0x14 duplicate labels
    int m_unknown18;                                         // +0x18 duplicate labels
    int m_unknown1C;                                         // +0x1C duplicate labels
    float m_unknown20;                                       // +0x20 duplicate label
    std::uint8_t m_unknown24[4];                             // +0x24
};

static_assert(offsetof(S_SkirmishStatistics, m_friends) == 0x08,
              "S_SkirmishStatistics::m_friends offset mismatch");
static_assert(offsetof(S_SkirmishStatistics, m_enemies) == 0x10,
              "S_SkirmishStatistics::m_enemies offset mismatch");
static_assert(offsetof(S_SkirmishStatistics, m_unknown20) == 0x20,
              "S_SkirmishStatistics::m_unknown20 offset mismatch");
static_assert(sizeof(S_SkirmishStatistics) == 0x28,
              "S_SkirmishStatistics size mismatch");

}  // namespace wh::rpgmodule
