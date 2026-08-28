#pragma once
#include <cstdint>

namespace wh::combatmodule {

struct E_WeaponKind {
    enum Type : std::uint8_t {
        none      = 0,
        melee     = 1,
        missile   = 2,
        oversized = 3,
        undefined = 4,
    };
};
static_assert(sizeof(E_WeaponKind::Type) == 1,
              "E_WeaponKind::Type size mismatch");

}  // namespace wh::combatmodule
