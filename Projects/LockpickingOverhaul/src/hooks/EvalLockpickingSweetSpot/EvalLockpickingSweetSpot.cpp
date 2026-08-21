#include "EvalLockpickingSweetSpot.h"

#include "LockpickOverhaul.h"
#include "REL.h"
#include "entitymodule/C_Actor.h"
#include "playermodule/C_LockPicking.h"

namespace hooks {

bool EvalLockpickingSweetSpotHook::Install()
{
    REL::Relocation<>{ REL::ID(47148), 0x195 }.write_call<6>(&EvalLockpickingSweetSpot);
    return true;
}

void EvalLockpickingSweetSpotHook::Uninstall()
{
}

bool EvalLockpickingSweetSpotHook::EvalLockpickingSweetSpot(wh::rpgmodule::I_RPGMinigames* rpg,
                                                            wh::rpgmodule::C_Soul* soul,
                                                            float difficulty,
                                                            wh::playermodule::E_InputDeviceClass::Type device,
                                                            float* outSweetSpot)
{
    const bool adequate = rpg->EvalLockpickingSweetSpot(soul, difficulty, device, outSweetSpot);

    auto* session = LockpickOverhaul::FindSession();
    if (!session || !outSweetSpot)
        return adequate;

    LockpickOverhaul::EnsureEngagement(rpg, soul, session->m_lockDifficulty, device);
    const int n = LockpickOverhaul::g_eng.n;
    if (n <= 1)
        return adequate;

    float dK = 0.f, tK = 0.f;
    LockpickOverhaul::CalcDkTk(rpg, soul, LockpickOverhaul::g_eng.d0, device,
                               LockpickOverhaul::g_eng.wins, n, &dK, &tK);
    *outSweetSpot = tK;

    if (!adequate)
        LockpickOverhaul::SwapTooHardKey();
    return adequate;
}

}  // namespace hooks
