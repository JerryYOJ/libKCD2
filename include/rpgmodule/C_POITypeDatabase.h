#pragma once
#include <cstdint>
#include <cstddef>
#include "S_POIType.h"
#include "S_POITypeDBData.h"
#include "../databasemodule/C_ObjectTableDatabase.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"

// -----------------------------------------------
// wh::rpgmodule::C_POITypeDatabase -- the poi_type table (KCD2 WHGame.dll 1.5.6, sjw7).
// -----------------------------------------------
// RTTI .?AVC_POITypeDatabase@rpgmodule@wh@@ (TD 0x184D39468). sizeof 0x98 (PROVEN:
// C_ObjectTableDatabase extent; KeyIndexed adds no members; ctor sub_18193ACF4 last
// write is m_loaded @+0x94).
// Stack: C_ObjectDatabaseKeyIndexed<C_ObjectTableDatabase<S_POIType,S_POITypeDBData>,
// C_ObjectDatabaseDefaultKeyExtractor<S_POIType>>.
// GLOBAL STATIC @0x18532DC50 (ctor table "poi_type", group "rpg"). m_objects @+0x30
// IS xmmword_18532DC80 -- the array I_RPGLocationManager[43..46] binary-search.

namespace wh::rpgmodule {

class C_POITypeDatabase
    : public wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTableDatabase<S_POIType, S_POITypeDBData>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_POIType>>
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_POITypeDatabase;
    static C_POITypeDatabase* GetInstance();
};
static_assert(sizeof(C_POITypeDatabase) == 0x98, "C_POITypeDatabase must be 0x98");
static_assert(offsetof(C_POITypeDatabase, m_objects) == 0x30, "m_objects at 0x30 (= xmmword_18532DC80)");

}  // namespace wh::rpgmodule
