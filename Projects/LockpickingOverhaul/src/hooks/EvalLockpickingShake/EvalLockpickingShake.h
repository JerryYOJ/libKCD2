#pragma once

#include "REL.h"
#include "rpgmodule/I_RPGMinigames.h"
#include "rpgmodule/C_Soul.h"

namespace hooks {

class EvalLockpickingShakeHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static float EvalLockpickingShake(wh::rpgmodule::I_RPGMinigames* rpg,
                                      wh::rpgmodule::C_Soul* soul,
                                      float turnProgress, float difficulty);

    inline static REL::Relocation<decltype(&EvalLockpickingShake)> orig;
};

}  // namespace hooks
