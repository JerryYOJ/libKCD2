#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::conceptmodule {

enum class E_NodeStyle : std::int32_t {
    General          = 0,
    Debug            = 1,
    Control          = 2,
    Arithmetic       = 3,
    Logical          = 4,
    Conversion       = 5,
    Module           = 6,
    State            = 7,
    ObjectProperties = 8,
    GeneralFunction  = 9,
    ArrayFunction    = 10,
    ItemFunction     = 11,
    SoulFunction     = 12,
    Effect           = 13,
    Trigger          = 14,
    AIGenerated      = 15,
    Combat           = 16,
};
static_assert(sizeof(E_NodeStyle) == 4, "E_NodeStyle size mismatch");

}  // namespace wh::conceptmodule
