#pragma once
#include <cstdint>

namespace wh::combatmodule::E_WeaponKind {

enum Type : std::int32_t {
    none      = 0,
    melee     = 1,
    missile   = 2,
    oversized = 3,
    undefined = 4,
};

}  // namespace wh::combatmodule::E_WeaponKind
