#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::E_SoulState -- continuous soul-state channels (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// Source identifiers for the behavior-proven channels are retained. RTTR adds
// Karma and proves the full runtime mapping health/stamina/exhaust/hunger/karma/
// alcoholism = 0..5.

namespace wh::rpgmodule {

enum class E_SoulState : std::uint32_t {
    Health     = 0,
    ActStamina = 1,
    Vigour     = 2,
    Food       = 3,
    Karma      = 4,
    Alcoholism = 5,
};
static_assert(sizeof(E_SoulState) == 4,
              "E_SoulState size mismatch");

}  // namespace wh::rpgmodule
