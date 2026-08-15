#pragma once
#include <cstdint>

namespace wh::playermodule {

// Source-reconstructed type name; the entity-script parser closes this byte domain.
enum class E_StoneThrowingOrientation : std::uint8_t {
    Left = 0,
    Right = 1,
};
static_assert(sizeof(E_StoneThrowingOrientation) == 0x01,
              "stone-throwing orientation must be one byte");

}  // namespace wh::playermodule
