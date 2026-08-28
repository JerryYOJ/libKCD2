#pragma once
#include <cstdint>
#include "../databasemodule/C_ObjectTableDatabase.h"
#include "C_CombatZoneData.h"
#include "S_CombatZoneDataDBData.h"

// -----------------------------------------------
// wh::combatmodule::C_CombatZoneDatabase -- combat_zone.tbl singleton (KCD2 1.5.6, kd7u).
// -----------------------------------------------
// Concrete leaf of C_CombatDatabase<C_AnimationDatabaseStaticIndexed<C_CombatZoneData,
// S_CombatZoneDataDBData>> (RTTI-named; those two templates are not yet their own headers).
// In-place static singleton @0x185321770 (Init sub_180E52640 returns &that global; primary
// vtable 0x183E5D540, 23 slots). GetById = sub_180934994: map find at this+0xD8, hit returns
// the C_CombatZoneData*, miss returns the default-constructed sentinel @unk_185594F10
// (ctor sub_1827B962C writes combat_zone_id = -1).
// I_QueryableDatabase MI @+0xE8 is degenerate here (1-slot dtor vtable 0x183E5D530) -- Init
// registers no query selectors. Tail past OTD (+0x98) is the unrecovered StaticIndexed /
// C_CombatDatabase / index-tree region -- use by pointer only, never sizeof.

namespace wh::combatmodule {

class C_CombatZoneDatabase
    : public wh::databasemodule::C_ObjectTableDatabase<C_CombatZoneData, S_CombatZoneDataDBData>
{
public:
    static C_CombatZoneDatabase* GetInstance();

    // sub_180934994 -- never null; miss is the sentinel (combat_zone_id == -1).
    const C_CombatZoneData& GetById(int32_t combatZoneId);
};

}  // namespace wh::combatmodule
