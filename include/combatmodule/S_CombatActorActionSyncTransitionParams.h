#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::combatmodule::S_CombatActorActionSyncTransitionParams -- params embedded by
// C_CombatActorActionSyncTransition (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0x18.
// -----------------------------------------------
// POD value struct -- NO vtable, NO RTTI TypeDescriptor (the SyncTransition base ctor sub_1810F2DD8
// writes plain data into obj+0x50..). Sits at action+0x50 (C_ParamAction::m_params).
//
// Layout proved by sub_1810F2DD8:
//   +0x50 (obj) = 0 (qword)  -> m_field0  (+0x00)
//   +0x58 (obj) = 0 (qword)  -> m_field8  (+0x08)
//   +0x60 (obj) = 0 (word)   -> m_field10 (+0x10)
// C_CombatActorObject base of the action begins at obj+0x68, confirming this struct ends at 0x18.
// Field roles UNVERIFIED (POD).

namespace wh::combatmodule {

struct S_CombatActorActionSyncTransitionParams {
    uint64_t m_field0;    // +0x00  (init 0)
    uint64_t m_field8;    // +0x08  (init 0)
    uint16_t m_field10;   // +0x10  (init 0)
    uint16_t _pad12[3];   // +0x12
};
static_assert(sizeof(S_CombatActorActionSyncTransitionParams) == 0x18);

}  // namespace wh::combatmodule
