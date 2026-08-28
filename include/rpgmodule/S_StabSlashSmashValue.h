#pragma once
#include <cstddef>

// -----------------------------------------------
// wh::rpgmodule::S_StabSlashSmashValue
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x0C. No vtable.
// -----------------------------------------------

namespace wh::rpgmodule {

struct S_StabSlashSmashValue {
    float m_stab;                                         // +0x00 RTTR "Stab"
    float m_slash;                                        // +0x04 RTTR "Slash"
    float m_smash;                                        // +0x08 RTTR "Smash"
};

static_assert(offsetof(S_StabSlashSmashValue, m_stab) == 0x00,
              "S_StabSlashSmashValue::m_stab offset mismatch");
static_assert(sizeof(S_StabSlashSmashValue) == 0x0C,
              "S_StabSlashSmashValue size mismatch");

}  // namespace wh::rpgmodule
