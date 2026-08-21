#pragma once
#include <cstddef>
#include <cstdint>

class IProceduralClip;

namespace wh::combatmodule {

struct S_CombatAppliedAlignment {
    std::int32_t     m_side;       // +0x00, 0 self / 1 opponent
    std::int32_t     m_channel;    // +0x04, 0 position / 1 rotation
    std::int32_t     m_handle;     // +0x08
    std::int32_t     m_entityId;   // +0x0C
    std::uint8_t     m_type;       // +0x10
    std::uint8_t     _pad11[7];    // +0x11
    IProceduralClip* m_pClip;      // +0x18, borrowed
};
static_assert(sizeof(S_CombatAppliedAlignment) == 0x20);
static_assert(offsetof(S_CombatAppliedAlignment, m_side) == 0x00);
static_assert(offsetof(S_CombatAppliedAlignment, m_handle) == 0x08);
static_assert(offsetof(S_CombatAppliedAlignment, m_type) == 0x10);
static_assert(offsetof(S_CombatAppliedAlignment, m_pClip) == 0x18);

}  // namespace wh::combatmodule
