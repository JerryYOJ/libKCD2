#include <MinHook.h>

#include "KCSE/KCSEAPI.h"

#include "crysystem/SSystemGlobalEnvironment.h"

#include "TruffleHoundMutt.h"
#include "hooks/hooks.h"
#include "mcm.h"
#include "persist.h"

KCSE_PLUGIN_INFO("TruffleHoundMutt", "JerryYOJ", 1);
KCSE_PLUGIN_LOAD(kcse)
{
    if (MH_Initialize() != MH_OK)
        return false;

    if (!hooks::Install())
        return false;

    TruffleHoundMutt::LoadPersistedEdits();

    // Soft dependency: without MCM.dll no sender="MCM" message ever arrives and the
    // mcm.h defaults (everything on) stand.
    MCM::ListenForMessages(&HandleMcmMessage);

    // The same knobs as console CVars, bound to the mcm.h ints (console exists by DataLoaded).
    kcse->GetMessagingInterface()->RegisterListener([](KCSE::Message* msg) {
        if (msg->type != KCSE::IMessagingInterface::kMessage_DataLoaded)
            return;
        TruffleHoundMutt::RegisterYields();
        auto* con = SSystemGlobalEnvironment::GetInstance()->pConsole;
        con->RegisterCVarInt("kcse_trufflehoundmutt_require_perk", &g_requirePerk,
            g_requirePerk, VF_NULL,
            "1 = Mutt only tracks wild herbs after the Truffle Hound perk is bought "
            "(Houndmaster tree, level 8).");
        con->RegisterCVarInt("kcse_trufflehoundmutt_show_beacon", &g_showBeacon,
            g_showBeacon, VF_NULL,
            "1 = mark the found plant with a shaft of light until the search ends.");
        con->RegisterCVarFloat("kcse_trufflehoundmutt_max_range", &g_maxRange,
            g_maxRange, VF_NULL,
            "Max metres from Mutt to a tracked plant (100..1000).");
    });
    return true;
}
