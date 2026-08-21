#include "ApplySMOutput.h"

#include <MinHook.h>

#include "Handling.h"

namespace hooks {

bool ApplySMOutputHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(56418).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&ApplySMOutput),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;
    return MH_EnableHook(target) == MH_OK;
}

void ApplySMOutputHook::Uninstall()
{
    MH_RemoveHook(reinterpret_cast<void*>(REL::ID(56418).address()));
}

char ApplySMOutputHook::ApplySMOutput(wh::entitymodule::C_RiderPlayerInput* self,
                                      wh::entitymodule::S_RiderSMOutput* smOut,
                                      wh::entitymodule::S_RiderMoveRequest* request,
                                      wh::entitymodule::S_HorseData* data, float dt)
{
    const float mag = self->m_stickMag;
    const float turn = self->m_turn;
    Handling::ApplyLookSteer(self, data);
    const char r = orig(self, smOut, request, data, dt);
    self->m_stickMag = mag;
    self->m_turn = turn;
    return r;
}

}  // namespace hooks
