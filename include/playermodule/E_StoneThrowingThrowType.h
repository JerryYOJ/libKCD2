#pragma once
#include <cstdint>

namespace wh::playermodule {

// Source-reconstructed type name; the entity-script parser closes this byte domain.
enum class E_StoneThrowingThrowType : std::uint8_t {
    Hole = 0,
    Walls = 1,
};
static_assert(sizeof(E_StoneThrowingThrowType) == 0x01,
              "stone-throwing throw type must be one byte");

}  // namespace wh::playermodule
