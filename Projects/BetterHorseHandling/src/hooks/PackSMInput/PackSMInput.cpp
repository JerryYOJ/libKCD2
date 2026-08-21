#include "PackSMInput.h"

#include <MinHook.h>

#include "Handling.h"

namespace hooks {

bool PackSMInputHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(56419).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&PackSMInput),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;
    return MH_EnableHook(target) == MH_OK;
}

void PackSMInputHook::Uninstall()
{
    MH_RemoveHook(reinterpret_cast<void*>(REL::ID(56419).address()));
}

int64_t PackSMInputHook::PackSMInput(wh::entitymodule::C_RiderPlayerInput* self,
                                     wh::entitymodule::S_RiderSMPackedInput* packed,
                                     wh::entitymodule::S_HorseData* data)
{
    const int64_t r = orig(self, packed, data);
    Handling::ApplyFollowPathInput(packed, data);
    Handling::ApplyLateralHoldInput(self, packed, data);
    Handling::ApplyGaitControl(self, packed);
    return r;
}

}  // namespace hooks
