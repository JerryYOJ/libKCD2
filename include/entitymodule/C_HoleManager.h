#pragma once
#include <cstddef>

#include "C_Hole.h"
#include "C_SaveExtensionManager.h"

namespace wh::entitymodule {

class C_HoleManager : public C_SaveExtensionManager<C_Hole> {
public:
    ~C_HoleManager() override; // [0] 0x181EC6900
};

static_assert(sizeof(C_HoleManager) == 0x98,
              "C_HoleManager size mismatch");

} // namespace wh::entitymodule
