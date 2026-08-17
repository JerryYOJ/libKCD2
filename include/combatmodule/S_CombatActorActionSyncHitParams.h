#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::combatmodule::S_CombatActorActionSyncHitParams -- params embedded by C_CombatActorActionSyncHit
// (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0x10.
// -----------------------------------------------
// POD value struct -- NO vtable, NO RTTI TypeDescriptor (the SyncHit base ctor sub_180D4A0AC writes
// plain data into obj+0x50..). Sits at action+0x50 (C_ParamAction::m_params).
//
// Layout proved by sub_180D4A0AC + the SyncHit factory sub_180D4A144. The factory's a3 is
// propagated from originating SyncAttack+0x60, where sub_180C61C28 stores the secondary
// S_CombatActionSyncHitData row selected for the victim. C_CombatActorObject begins at obj+0x60.

namespace wh::combatmodule {

class S_CombatActionSyncHitData;

struct S_CombatActorActionSyncHitParams {
    S_CombatActionSyncHitData* m_pDataRow; // +0x00  victim-side typed action row
    bool                       m_flag8;     // +0x08  init 0; set by factory
    uint8_t                    _pad9[7];    // +0x09
};
static_assert(sizeof(S_CombatActorActionSyncHitParams) == 0x10);

}  // namespace wh::combatmodule
