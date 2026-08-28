#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include <memory>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectTreeDatabaseKeyIndexed.h"
#include "C_Faction.h"

namespace wh::rpgmodule {

using C_FactionTreeDatabaseBase = wh::databasemodule::C_ObjectTreeDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<std::shared_ptr<C_Faction>>,
          std::map<CryStringT<char>, std::shared_ptr<C_Faction>>>;

class C_FactionTreeDatabase : public C_FactionTreeDatabaseBase {
public:
    ~C_FactionTreeDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_FactionTreeDatabase) == 0x88,
              "C_FactionTreeDatabase size mismatch");

} // namespace wh::rpgmodule
