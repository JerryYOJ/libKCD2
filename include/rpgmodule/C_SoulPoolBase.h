#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::rpgmodule {
class C_SoulPoolBase {
public:
    virtual ~C_SoulPoolBase();
    virtual void unk_01();
    virtual void unk_02();
    RTTR_ENABLE()  // [3..5]
    CryStringT<char> m_name;  // +0x8 RTTR "Name"
    float m_combatLevelMin;  // +0x10 RTTR "CombatLevelMin"
    float m_combatLevelMax;  // +0x14 RTTR "CombatLevelMax"
};

static_assert(offsetof(C_SoulPoolBase, m_combatLevelMax) == 0x14, "C_SoulPoolBase::m_combatLevelMax offset mismatch");
static_assert(offsetof(C_SoulPoolBase, m_combatLevelMin) == 0x10, "C_SoulPoolBase::m_combatLevelMin offset mismatch");
static_assert(offsetof(C_SoulPoolBase, m_name) == 0x8, "C_SoulPoolBase::m_name offset mismatch");
static_assert(sizeof(C_SoulPoolBase) == 0x18, "C_SoulPoolBase size mismatch");

}  // namespace wh::rpgmodule
