#pragma once

#include <cstdint>

#include "playermodule/C_LockPicking.h"
#include "rpgmodule/C_Soul.h"
#include "rpgmodule/I_RPGMinigames.h"
#include "guimodule/C_UIHudMessages.h"

namespace LockpickOverhaul {

inline constexpr const char* kTooHardKey = "ui_lp_overhaul_too_hard";
inline constexpr const char* kProgressKey = "ui_lp_overhaul_progress";
inline constexpr const char* kVanillaTooHardKey = "dlg_lp_difficult_info";

struct Engagement {
    float d0 = 0.f;
    int   wins = 0;
    int   n = 1;      // total rounds, fixed when the engagement starts
    bool  active = false;
};

extern Engagement g_eng;
extern bool       g_keySwapped;

wh::playermodule::C_LockPicking* FindSession();
wh::rpgmodule::I_RPGMinigames*   Minigames();
wh::guimodule::C_UIHudMessages*  FindHud();

int   CalcN(wh::rpgmodule::I_RPGMinigames* rpg, wh::rpgmodule::C_Soul* soul,
            float d0, wh::playermodule::E_InputDeviceClass::Type device);
void  CalcDkTk(wh::rpgmodule::I_RPGMinigames* rpg, wh::rpgmodule::C_Soul* soul,
               float d0, wh::playermodule::E_InputDeviceClass::Type device,
               int wins, int n, float* dK, float* tK);
float DifficultyFromT(wh::rpgmodule::I_RPGMinigames* rpg, wh::rpgmodule::C_Soul* soul,
                      float t, wh::playermodule::E_InputDeviceClass::Type device);
float BandAngle(float d);
void  EnsureEngagement(wh::rpgmodule::I_RPGMinigames* rpg, wh::rpgmodule::C_Soul* soul,
                       float d0, wh::playermodule::E_InputDeviceClass::Type device);
void  ClearEngagement();
int   BestWins(uint32_t lockEntityId);
void  RecordBestWins(uint32_t lockEntityId, int wins);
void  ForgetLock(uint32_t lockEntityId);

void SwapTooHardKey();
void RestoreTooHardKey();
void ShowProgressToast();
void BeginNextRound(wh::playermodule::C_LockPicking* session);

}  // namespace LockpickOverhaul

