#include "EvalLockpickingShake.h"

#include <MinHook.h>

#include "LockpickOverhaul.h"
#include "mcm.h"

namespace hooks {

bool EvalLockpickingShakeHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(47218).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&EvalLockpickingShake),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;
    return MH_EnableHook(target) == MH_OK;
}

void EvalLockpickingShakeHook::Uninstall()
{
    MH_RemoveHook(reinterpret_cast<void*>(REL::ID(47218).address()));
}

float EvalLockpickingShakeHook::EvalLockpickingShake(wh::rpgmodule::I_RPGMinigames* rpg,
                                                     wh::rpgmodule::C_Soul* soul,
                                                     float turnProgress, float difficulty)
{
    if (LockpickOverhaul::g_eng.active) {
        auto* session = LockpickOverhaul::FindSession();
        if (session && session->m_sweetSpot > 1e-6f) {
            difficulty = LockpickOverhaul::DifficultyFromT(
                rpg, soul, session->m_sweetSpot, session->m_inputDeviceClass);
        }
    }
    return orig(rpg, soul, turnProgress, difficulty) * g_shakeScale;
}

}  // namespace hooks
