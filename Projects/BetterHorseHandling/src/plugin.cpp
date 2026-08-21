#include <MinHook.h>

#include "KCSE/KCSEAPI.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "Offsets/vtables/IConsole.h"

#include "Handling.h"
#include "hooks/hooks.h"

KCSE_PLUGIN_INFO("BetterHorseHandling", "JerryYOJ", 1);
KCSE_PLUGIN_LOAD(kcse)
{
    if (MH_Initialize() != MH_OK)
        return false;
    if (!hooks::Install())
        return false;

    kcse->GetMessagingInterface()->RegisterListener([](KCSE::Message* msg) {
        if (msg->type != KCSE::IMessagingInterface::kMessage_DataLoaded)
            return;
        auto* con = SSystemGlobalEnvironment::GetInstance()->pConsole;
        con->RegisterCVarInt("kcse_horse_looksteer", &Handling::g_enableLookSteer,
                             Handling::g_enableLookSteer, 0,
                             "1 = camera-relative steering.");
        con->RegisterCVarFloat("kcse_horse_looksteer_rate", &Handling::g_lookSteerRate,
                               Handling::g_lookSteerRate, 0,
                               "Steer P-gain (negative flips polarity).");
        con->RegisterCVarFloat("kcse_horse_looksteer_key_weight", &Handling::g_keyWeight,
                               Handling::g_keyWeight, 0,
                               "A/D vs W weight. 1 = equal, >1 = A/D counts more.");
        con->RegisterCVarFloat("kcse_horse_hold_threshold", &Handling::g_holdThreshold,
                               Handling::g_holdThreshold, 0,
                               "Seconds of Shift hold before dash; shorter is a tap.");
        con->RegisterCVarInt("kcse_horse_gait_low", &Handling::g_gaitLow,
                             Handling::g_gaitLow, 0,
                             "Unlatched cruise gait: 2 = walk, 3 = run, 4 = trot.");
        con->RegisterCVarInt("kcse_horse_gait_high", &Handling::g_gaitHigh,
                             Handling::g_gaitHigh, 0,
                             "Latched cruise gait (Shift tap): 2 = walk, 3 = run, 4 = trot.");
        con->RegisterCVarInt("kcse_horse_camera_turret", &Handling::g_enableCameraTurret,
                             Handling::g_enableCameraTurret, 0,
                             "1 = turret aim on horseback.");
        con->RegisterCVarInt("kcse_horse_gait_during_follow", &Handling::g_enableGaitDuringFollow,
                             Handling::g_enableGaitDuringFollow, 0,
                             "1 = gait system stays live during road-follow.");
    });
    return true;
}
