#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::combatmodule::E_CombatSlotId::Type -- KCD2 1.5.6 (kd7u).  1-byte enum.
// -----------------------------------------------
// RTTR: struct wh::combatmodule::E_CombatSlotId / enum Type (N=8, vtable 0x183E5D940,
// stack-array registrar sub_1800C9720). Values are the ids CollectActiveSlots
// (C_CombatActor vt[42]) pushes from the live trigger/window properties.

namespace wh::combatmodule {

struct E_CombatSlotId {
    enum Type : std::uint8_t {
        Undefined        = 0,
        PerfectBlock     = 1,
        Riposte          = 2,
        Combo            = 3,
        SyncPerfectBlock = 4,
        MasterStrike     = 5,
        Block            = 6,
        Dodge            = 7,
    };
};
static_assert(sizeof(E_CombatSlotId::Type) == 1,
              "E_CombatSlotId::Type size mismatch");

}  // namespace wh::combatmodule
