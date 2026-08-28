#pragma once
#include "../animationmodule/C_AnimationDatabaseBase.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"

namespace wh::combatmodule {

template <typename TData>
using C_CombatTreeKeyIndexedDatabaseStorage =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<TData>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<TData>>;

template <typename TData>
class C_CombatTreeKeyIndexedDatabase
    : public wh::animationmodule::C_AnimationDatabaseBase<
          TData,
          void,
          C_CombatTreeKeyIndexedDatabaseStorage<TData>> {};

}  // namespace wh::combatmodule
