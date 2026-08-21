#include "RiderInputUpdate.h"

#include <MinHook.h>

#include "Handling.h"

namespace hooks {

bool RiderInputUpdateHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(56411).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&Update),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;
    return MH_EnableHook(target) == MH_OK;
}

void RiderInputUpdateHook::Uninstall()
{
    MH_RemoveHook(reinterpret_cast<void*>(REL::ID(56411).address()));
}

void RiderInputUpdateHook::Update(wh::entitymodule::C_RiderPlayerInput* self,
                                  wh::entitymodule::S_HorseData* data, float dt)
{
    Handling::ArmFollowTick(self, data);
    orig(self, data, dt);
}

}  // namespace hooks
