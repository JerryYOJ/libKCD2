#pragma once

#include "EvalLockpickingSweetSpot/EvalLockpickingSweetSpot.h"
#include "EvalLockpickingShake/EvalLockpickingShake.h"
#include "EnterComplete/EnterComplete.h"
#include "CommitResult/CommitResult.h"
#include "LockPickingTeardown/LockPickingTeardown.h"

namespace hooks {

inline bool Install()
{
    return EvalLockpickingSweetSpotHook::Install()
        && EvalLockpickingShakeHook::Install()
        && EnterCompleteHook::Install()
        && CommitResultHook::Install()
        && LockPickingTeardownHook::Install();
}

inline void Uninstall()
{
    LockPickingTeardownHook::Uninstall();
    CommitResultHook::Uninstall();
    EnterCompleteHook::Uninstall();
    EvalLockpickingShakeHook::Uninstall();
    EvalLockpickingSweetSpotHook::Uninstall();
}

}  // namespace hooks
