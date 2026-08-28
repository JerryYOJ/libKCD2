#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::guimodule::E_BlockUINotificationType -- KCD2 WHGame.dll 1.5.6 (kd7u).  Enum wrapper.
// -----------------------------------------------
// UI-notification category selector of C_BlockUINotifications. Exact labels,
// values, and unsigned-byte underlying type are RTTR-proven.

namespace wh::guimodule {

struct E_BlockUINotificationType {
    enum Type : std::uint8_t {
        Common     = 0,
        Compass    = 1,
        Crime      = 2,
        StaminaBar = 3,
        Buffs      = 4,
        Cursor     = 5,
        LevelUp    = 6,
        Flush      = 7,
    };
};
static_assert(sizeof(E_BlockUINotificationType::Type) == 1,
              "E_BlockUINotificationType::Type size mismatch");

}  // namespace wh::guimodule
