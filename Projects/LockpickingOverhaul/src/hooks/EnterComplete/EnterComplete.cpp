#include "EnterComplete.h"

#include <MinHook.h>

#include "LockpickOverhaul.h"
#include "entitymodule/C_Actor.h"
#include "rpgmodule/I_RPGMinigames.h"

namespace hooks {

bool EnterCompleteHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(47157).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&EnterComplete),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;
    return MH_EnableHook(target) == MH_OK;
}

void EnterCompleteHook::Uninstall()
{
    MH_RemoveHook(reinterpret_cast<void*>(REL::ID(47157).address()));
}

void EnterCompleteHook::EnterComplete(wh::playermodule::C_LockPicking* self)
{
    orig(self);
    if (!self || !LockpickOverhaul::g_eng.active)
        return;

    auto* rpg = LockpickOverhaul::Minigames();
    auto* soul = self->m_pPlayerActor ? self->m_pPlayerActor->m_pSoul : nullptr;
    const auto device = self->m_inputDeviceClass;
    const int n = LockpickOverhaul::g_eng.n;
    if (n <= 1)
        return;

    float dK = 0.f, tK = 0.f;
    LockpickOverhaul::CalcDkTk(rpg, soul, LockpickOverhaul::g_eng.d0, device,
                               LockpickOverhaul::g_eng.wins, n, &dK, &tK);
    self->m_startAngle = LockpickOverhaul::BandAngle(dK);
}

}  // namespace hooks
