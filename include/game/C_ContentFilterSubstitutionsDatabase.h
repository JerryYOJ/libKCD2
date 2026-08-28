#pragma once
#include <cstddef>
#include <memory>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "C_ContentFilterSubstitution.h"

namespace wh::game {

class C_ContentFilterSubstitutionsDatabase
    : public wh::databasemodule::C_ObjectTreeDatabase<
          std::shared_ptr<C_ContentFilterSubstitution>> {
public:
    ~C_ContentFilterSubstitutionsDatabase() override;         // [0] 0x1829170A0
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)    // [18..20]
};

static_assert(sizeof(C_ContentFilterSubstitutionsDatabase) == 0x78,
              "C_ContentFilterSubstitutionsDatabase size mismatch");

}  // namespace wh::game
