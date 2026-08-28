#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "S_ForgeSlot.h"

namespace wh::playermodule {

using C_ForgeSlotDatabaseBase = wh::databasemodule::C_ObjectTreeDatabase<S_ForgeSlot>;

class C_ForgeSlotDatabase : public C_ForgeSlotDatabaseBase {
public:
    ~C_ForgeSlotDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ForgeSlotDatabase) == 0x78,
              "C_ForgeSlotDatabase size mismatch");

} // namespace wh::playermodule
