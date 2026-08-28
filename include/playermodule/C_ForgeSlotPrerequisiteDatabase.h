#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "S_ForgeSlotPrerequisite.h"

namespace wh::playermodule {

using C_ForgeSlotPrerequisiteDatabaseBase = wh::databasemodule::C_ObjectTreeDatabase<S_ForgeSlotPrerequisite>;

class C_ForgeSlotPrerequisiteDatabase : public C_ForgeSlotPrerequisiteDatabaseBase {
public:
    ~C_ForgeSlotPrerequisiteDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ForgeSlotPrerequisiteDatabase) == 0x78,
              "C_ForgeSlotPrerequisiteDatabase size mismatch");

} // namespace wh::playermodule
