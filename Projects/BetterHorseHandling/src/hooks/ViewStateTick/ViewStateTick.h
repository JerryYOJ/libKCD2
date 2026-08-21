#pragma once

#include <cstdint>

#include "REL.h"
#include "entitymodule/C_ActorPhysicsState.h"
#include "entitymodule/S_MountAnimState.h"

namespace hooks {

// C_ActorPhysicsState tick, REL::ID 26156.
class ViewStateTickHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static int64_t Tick(wh::entitymodule::C_ActorPhysicsState* viewState,
                        wh::entitymodule::S_MountAnimState* frameSrc);

    inline static REL::Relocation<decltype(&Tick)> orig;
};

}  // namespace hooks
