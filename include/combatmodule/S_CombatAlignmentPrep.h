#pragma once
#include <cstddef>
#include <cstdint>
#include "E_CombatAlignmentType.h"
#include "../CryEngine/CryCommon/CryString.h"

class IProceduralClip;

namespace wh::combatmodule {

struct S_CombatAlignmentPrep {
    E_CombatAlignmentType::Type m_type;    // +0x00
    std::uint8_t                _pad01[3];  // +0x01
    float                       m_paramA;   // +0x04, semantic spelling not emitted
    float                       m_paramB;   // +0x08, semantic spelling not emitted
    std::uint32_t               _pad0C;     // +0x0C
    IProceduralClip*            m_pClip;    // +0x10, borrowed
    std::int32_t                m_paramC;   // +0x18, semantic spelling not emitted
    std::uint32_t               _pad1C;     // +0x1C
    CryStringT<char>            m_name;     // +0x20
    bool                        m_flag;     // +0x28, semantic spelling not emitted
    std::uint8_t                _pad29[7];  // +0x29
};
static_assert(sizeof(S_CombatAlignmentPrep) == 0x30);
static_assert(offsetof(S_CombatAlignmentPrep, m_type) == 0x00);
static_assert(offsetof(S_CombatAlignmentPrep, m_pClip) == 0x10);
static_assert(offsetof(S_CombatAlignmentPrep, m_name) == 0x20);
static_assert(offsetof(S_CombatAlignmentPrep, m_flag) == 0x28);

}  // namespace wh::combatmodule
