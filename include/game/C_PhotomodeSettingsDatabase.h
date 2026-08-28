#pragma once
#include <cstddef>
#include <memory>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "C_PhotomodeUIElementBase.h"

namespace wh::game {

class C_PhotomodeSettingsDatabase
    : public wh::databasemodule::C_ObjectTreeDatabase<
          std::shared_ptr<C_PhotomodeUIElementBase>> {
public:
    ~C_PhotomodeSettingsDatabase() override;                  // [0] 0x181EB2950
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)    // [18..20]
};

static_assert(sizeof(C_PhotomodeSettingsDatabase) == 0x78,
              "C_PhotomodeSettingsDatabase size mismatch");

}  // namespace wh::game
