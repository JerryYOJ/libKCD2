#include <MinHook.h>

#include "KCSE/KCSEAPI.h"
#include "FastTravel.h"
#include "hooks/hooks.h"
#include "input/MapInput/MapInput.h"
#include "tasks/Tick/Tick.h"

KCSE_PLUGIN_INFO("Navigation", "JerryYOJ", 1);
KCSE_PLUGIN_LOAD(kcse)
{
    if (MH_Initialize() != MH_OK)
        return false;
    if (!hooks::Install())
        return false;

    kcse->GetMessagingInterface()->RegisterListener([](KCSE::Message* msg) {
        if (msg->type == KCSE::IMessagingInterface::kMessage_LoadGame)
        {
            FastTravel::HideLine(nullptr);
            return;
        }
        if (msg->type != KCSE::IMessagingInterface::kMessage_DataLoaded)
            return;
        MapInput::Install();
        KCSE::GetTaskInterface()->AddTask(&NavigationTick);
    });
    return true;
}
