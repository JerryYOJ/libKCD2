#include "PickDestination.h"

#include <MinHook.h>

#include "TruffleHoundMutt.h"

namespace hooks {

bool PickDestinationHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(406230).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&PickDestination),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;

    return MH_EnableHook(target) == MH_OK;
}

void PickDestinationHook::Uninstall()
{
    MH_RemoveHook(reinterpret_cast<void*>(REL::ID(406230).address()));
}

void PickDestinationHook::PickDestination(
    wh::xgenaimodule::activitysystem::C_SearchItemDogObjective* self)
{
    if (TruffleHoundMutt::TryHerbTrack(self))
        return;
    orig(self);
}

}  // namespace hooks
