#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_QuickSlotSpec -- KCD2 WHGame.dll 1.5.6 (kd7u).  Enum wrapper, Type : int32.
// -----------------------------------------------
// Nested-Type enum wrapper (RTTR W4Type@E_QuickSlotSpec, wrapper
// enumeration_wrapper<...E_QuickSlotSpec::Type,6,0>). Enumerators certified from
// the RTTR registration sub_180129670 (name strings @0x183eaeec8..0x183eaef38).
// Consumed by C_EquipmentManager's S_EquipmentSlotIdWrapper::quickSlotSpec.

namespace wh::entitymodule {

struct E_QuickSlotSpec {
    enum Type : int32_t {
        QuickSlot1                 = 0,
        QuickSlot2                 = 1,
        QuickSlot3                 = 2,
        QuickSlot4                 = 3,
        QuickSlotMatchingWeaponSet = 4,
        Default                    = 5,
    };
};

}  // namespace wh::entitymodule
