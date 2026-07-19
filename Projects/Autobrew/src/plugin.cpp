#include <MinHook.h>

#include "KCSE/KCSEAPI.h"

#include "crysystem/SSystemGlobalEnvironment.h"

#include "Autobrew.h"
#include "hooks/hooks.h"
#include "mcm.h"

KCSE_PLUGIN_INFO("Autobrew", "JerryYOJ", 1);
KCSE_PLUGIN_LOAD(kcse)
{
    if (MH_Initialize() != MH_OK)
        return false;

    if (!hooks::Install())
        return false;

    Autobrew::OnPluginLoad();

    // Soft dependency: without MCM.dll no sender="MCM" message ever arrives and the
    // mcm.h defaults (everything on) stand.
    MCM::ListenForMessages(&HandleMcmMessage);

    // The same knobs as console CVars, bound to the mcm.h ints (console exists by DataLoaded).
    kcse->GetMessagingInterface()->RegisterListener([](KCSE::Message* msg) {
        if (msg->type != KCSE::IMessagingInterface::kMessage_DataLoaded)
            return;
        auto* con = SSystemGlobalEnvironment::GetInstance()->pConsole;
        con->RegisterCVarInt("kcse_autobrew_enable", &g_enableAutobrew, g_enableAutobrew,
            VF_NULL, "Autobrew master switch (start gate): 1 = show the Auto Brew prompt.");
        con->RegisterCVarInt("kcse_autobrew_enable_looping", &g_enableLooping, g_enableLooping,
            VF_NULL, "1 = rebrew until ingredients run out (results as toasts); 0 = one brew "
            "per press with the vanilla result popup.");
    });
    return true;
}
