#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::combatmodule {

struct S_CombatActorTimewarpConfiguration {
    float        m_delay;              // +0x00, default 0
    float        m_duration;           // +0x04, default 1
    float        m_fadeIn;             // +0x08, default 0
    float        m_fadeOut;            // +0x0C, default 0
    float        m_timeScale;          // +0x10, default 0
    bool         m_enablePlayerEffect; // +0x14, default true
    std::uint8_t _pad15[3];            // +0x15
};
static_assert(sizeof(S_CombatActorTimewarpConfiguration) == 0x18);
static_assert(offsetof(S_CombatActorTimewarpConfiguration, m_delay) == 0x00);
static_assert(offsetof(S_CombatActorTimewarpConfiguration, m_timeScale) == 0x10);
static_assert(offsetof(S_CombatActorTimewarpConfiguration, m_enablePlayerEffect) == 0x14);

}  // namespace wh::combatmodule
