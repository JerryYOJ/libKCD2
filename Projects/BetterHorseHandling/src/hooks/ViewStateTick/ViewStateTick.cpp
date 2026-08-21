#include "ViewStateTick.h"

#include <MinHook.h>

#include "Handling.h"

namespace hooks {

bool ViewStateTickHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(26156).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&Tick),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;
    return MH_EnableHook(target) == MH_OK;
}

void ViewStateTickHook::Uninstall()
{
    MH_RemoveHook(reinterpret_cast<void*>(REL::ID(26156).address()));
}

int64_t ViewStateTickHook::Tick(wh::entitymodule::C_ActorPhysicsState* viewState,
                                wh::entitymodule::S_MountAnimState* frameSrc)
{
    Handling::SyncRideSession();
    Handling::ApplyTurretCompensation(viewState);
    return orig(viewState, frameSrc);
}

}  // namespace hooks
