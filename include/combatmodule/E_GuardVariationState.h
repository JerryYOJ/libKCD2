#pragma once
#include <cstdint>

namespace wh::combatmodule {

enum class E_GuardVariationState : std::int32_t {
    Idle    = 0,
    Loop    = 1,
    OneShot = 2,
};

}  // namespace wh::combatmodule
