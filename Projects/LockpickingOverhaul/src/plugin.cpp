#include <MinHook.h>

#include "KCSE/KCSEAPI.h"
#include "KCSE/Trampoline.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "Offsets/vtables/IConsole.h"

#include "hooks/hooks.h"
#include "mcm.h"
#include "persist.h"

KCSE_PLUGIN_INFO("LockpickingOverhaul", "JerryYOJ", 1);
KCSE_PLUGIN_LOAD(kcse)
{
    KCSE::AllocTrampoline(1 << 10);
    if (MH_Initialize() != MH_OK)
        return false;
    if (!hooks::Install())
        return false;

    LockpickOverhaul::LoadPersistedEdits();
    MCM::ListenForMessages(&HandleMcmMessage);

    kcse->GetMessagingInterface()->RegisterListener([](KCSE::Message* msg) {
        if (msg->type != KCSE::IMessagingInterface::kMessage_DataLoaded)
            return;
        auto* con = SSystemGlobalEnvironment::GetInstance()->pConsole;
        con->RegisterCVarFloat(kCvarFactor, &g_factor, g_factor, 0,
                               "Lockpick overhaul attempt-count factor.");
        con->RegisterCVarFloat(kCvarTScale, &g_tScale, g_tScale, 0,
                               "First-attempt gold radius as a multiple of AppropriateTolerance.");
        con->RegisterCVarFloat(kCvarShakeScale, &g_shakeScale, g_shakeScale, 0,
                               "Lockpick overhaul cursor-shake scale.");
    });
    return true;
}
