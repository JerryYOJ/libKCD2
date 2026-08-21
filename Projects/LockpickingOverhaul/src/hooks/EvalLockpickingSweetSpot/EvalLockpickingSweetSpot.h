#pragma once

#include "rpgmodule/I_RPGMinigames.h"
#include "rpgmodule/C_Soul.h"

namespace hooks {

class EvalLockpickingSweetSpotHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static bool EvalLockpickingSweetSpot(wh::rpgmodule::I_RPGMinigames* rpg,
                                         wh::rpgmodule::C_Soul* soul, float difficulty,
                                         wh::playermodule::E_InputDeviceClass::Type device,
                                         float* outSweetSpot);
};

}  // namespace hooks
