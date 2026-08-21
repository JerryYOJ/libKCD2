#pragma once

#include "PackSMInput/PackSMInput.h"
#include "ApplySMOutput/ApplySMOutput.h"
#include "RiderInputUpdate/RiderInputUpdate.h"
#include "ViewStateTick/ViewStateTick.h"

namespace hooks {

inline bool Install()
{
    return PackSMInputHook::Install()
        && ApplySMOutputHook::Install()
        && RiderInputUpdateHook::Install()
        && ViewStateTickHook::Install();
}

inline void Uninstall()
{
    ViewStateTickHook::Uninstall();
    RiderInputUpdateHook::Uninstall();
    ApplySMOutputHook::Uninstall();
    PackSMInputHook::Uninstall();
}

}  // namespace hooks
