#include "CommitResult.h"

#include <MinHook.h>

#include "LockpickOverhaul.h"
#include "entitymodule/C_Actor.h"
#include "rpgmodule/I_RPGMinigames.h"

namespace hooks {

bool CommitResultHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(47176).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&CommitResult),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;
    return MH_EnableHook(target) == MH_OK;
}

void CommitResultHook::Uninstall()
{
    MH_RemoveHook(reinterpret_cast<void*>(REL::ID(47176).address()));
}

void CommitResultHook::CommitResult(wh::playermodule::C_LockPicking* self, uint8_t success,
                                    char skipLeave, void* scratch)
{
    if (!self || scratch || !LockpickOverhaul::g_eng.active) {
        orig(self, success, skipLeave, scratch);
        return;
    }

    auto* rpg = LockpickOverhaul::Minigames();
    auto* soul = self->m_pPlayerActor ? self->m_pPlayerActor->m_pSoul : nullptr;
    const auto device = self->m_inputDeviceClass;
    const int n = LockpickOverhaul::g_eng.n;
    if (n <= 1) {
        orig(self, success, skipLeave, scratch);
        return;
    }

    float dK = 0.f, tK = 0.f;
    LockpickOverhaul::CalcDkTk(rpg, soul, LockpickOverhaul::g_eng.d0, device,
                               LockpickOverhaul::g_eng.wins, n, &dK, &tK);

    ++LockpickOverhaul::g_eng.wins;

    if (LockpickOverhaul::g_eng.wins >= n) {
        LockpickOverhaul::ForgetLock(self->m_targetEntityId);
        LockpickOverhaul::RestoreTooHardKey();
        LockpickOverhaul::ClearEngagement();
        orig(self, success, skipLeave, scratch);
        return;
    }

    // Intermediate XP only on a new best for this lock: walking away and
    // re-winning the same early rounds must not pay again.
    if (rpg && soul && success &&
        LockpickOverhaul::g_eng.wins > LockpickOverhaul::BestWins(self->m_targetEntityId)) {
        LockpickOverhaul::RecordBestWins(self->m_targetEntityId, LockpickOverhaul::g_eng.wins);
        int outFlag = 0;
        rpg->GrantLockpickingResult(soul, dK, success, self->m_breakCount, &outFlag, scratch);
    }
    self->StampLockpickTime();
    LockpickOverhaul::ShowProgressToast();
    LockpickOverhaul::BeginNextRound(self);
}

}  // namespace hooks
