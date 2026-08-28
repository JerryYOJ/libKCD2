#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::framework {

struct E_EnumExample {
    enum Type : std::uint8_t {
        First  = 0,
        Second = 1,
        Third  = 2,
    };
};
static_assert(sizeof(E_EnumExample::Type) == 1, "E_EnumExample::Type size mismatch");

}  // namespace wh::framework
