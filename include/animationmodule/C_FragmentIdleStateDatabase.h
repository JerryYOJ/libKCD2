#pragma once
#include <cstddef>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "S_FragmentIdleStateData.h"

namespace wh::animationmodule {

class C_FragmentIdleStateDatabase
    : public wh::databasemodule::C_ObjectTreeDatabase<S_FragmentIdleStateData> {
public:
    ~C_FragmentIdleStateDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)    // [18..20]
};

static_assert(sizeof(C_FragmentIdleStateDatabase) == 0x78,
              "C_FragmentIdleStateDatabase size mismatch");

}  // namespace wh::animationmodule
