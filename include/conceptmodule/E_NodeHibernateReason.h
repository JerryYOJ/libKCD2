#pragma once
#include <cstdint>

// wh::conceptmodule::E_NodeHibernateReason -- reason supplied while hibernating a graph.
// Values are from RTTR registration 0x1800A96B0.

namespace wh::conceptmodule {

enum class E_NodeHibernateReason : uint32_t {
    GameModeEnd            = 0,
    GraphUnload            = 1,
    RandomEventEnd         = 2,
    RuntimeConditionPassed = 3,
    Debug                  = 4,
};

}  // namespace wh::conceptmodule
