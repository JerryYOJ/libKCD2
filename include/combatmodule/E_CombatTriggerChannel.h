#pragma once
#include <cstdint>

namespace wh::combatmodule {

enum class E_CombatTriggerChannel : std::int32_t {
    PerfectBlock     = 4,
    SyncPerfectBlock = 6,
    MasterStrike     = 8,
    Dodge            = 10,
};

}  // namespace wh::combatmodule
