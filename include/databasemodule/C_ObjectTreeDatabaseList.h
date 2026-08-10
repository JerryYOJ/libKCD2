#pragma once
#include <list>
#include "C_ObjectTreeDatabase.h"

namespace wh::databasemodule {

// Compatibility alias; no distinct binary C_ObjectTreeDatabaseList RTTI class exists.
template <typename TObject>
using C_ObjectTreeDatabaseList = C_ObjectTreeDatabase<TObject, std::list>;

}  // namespace wh::databasemodule
