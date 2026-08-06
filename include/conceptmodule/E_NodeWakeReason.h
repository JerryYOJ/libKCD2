#pragma once
#include <cstdint>

// wh::conceptmodule::E_NodeWakeReason -- reason supplied while waking a graph.
// Values are from RTTR registration 0x1800A9010.

namespace wh::conceptmodule {

enum class E_NodeWakeReason : uint32_t {
    GameStart              = 0,
    RandomEventStart       = 1,
    RuntimeConditionPassed = 2,
    Debug                  = 3,
};

}  // namespace wh::conceptmodule
