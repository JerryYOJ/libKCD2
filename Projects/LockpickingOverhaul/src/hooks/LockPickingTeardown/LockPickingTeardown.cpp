#include "LockPickingTeardown.h"

#include <MinHook.h>

#include "LockpickOverhaul.h"

namespace hooks {

bool LockPickingTeardownHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(47189).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&Teardown),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;
    return MH_EnableHook(target) == MH_OK;
}

void LockPickingTeardownHook::Uninstall()
{
    MH_RemoveHook(reinterpret_cast<void*>(REL::ID(47189).address()));
}

void LockPickingTeardownHook::Teardown(wh::playermodule::C_LockPicking* self)
{
    LockpickOverhaul::RestoreTooHardKey();
    LockpickOverhaul::ClearEngagement();
    orig(self);
}

}  // namespace hooks
