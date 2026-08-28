#pragma once
#include <cstddef>
#include <vector>

#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "I_DoorAnimSetDatabase.h"
#include "S_DoorAnimSet.h"

namespace wh::entitymodule {

using C_DoorAnimSetDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabase<S_DoorAnimSet, std::vector>;

class C_DoorAnimSetDatabase
    : public C_DoorAnimSetDatabaseBase,
      public I_DoorAnimSetDatabase {
public:
    ~C_DoorAnimSetDatabase() override; // primary [0] 0x1829DEE40
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // primary [18..20]

    const S_DoorAnimSet* FindByTags(const char* tags) const override; // secondary [0] 0x1804CF834
    const S_DoorAnimSet* FindForDoor(const C_AnimDoor* door) const override; // secondary [1] 0x1804CF7EC
};

static_assert(sizeof(C_DoorAnimSetDatabaseBase) == 0x78,
              "C_DoorAnimSetDatabaseBase size mismatch");
static_assert(sizeof(C_DoorAnimSetDatabase) == 0x80,
              "C_DoorAnimSetDatabase size mismatch");

} // namespace wh::entitymodule
