#pragma once
#include <cstdint>

namespace wh::combatmodule::E_GuardRequestScope {

enum Type : std::int32_t {
    PlayerController        = 0,
    PlayerControllerMounted = 1,
    GuardAutomation         = 2,
    DebugBrain              = 3,
    TestCommand             = 4,
    FreeAttack              = 5,
    FreeBlock               = 6,
    Stealth                 = 7,
    Last                    = 8,
};

}  // namespace wh::combatmodule::E_GuardRequestScope
