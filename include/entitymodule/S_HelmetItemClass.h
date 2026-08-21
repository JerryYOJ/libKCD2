#pragma once
#include <cstddef>
#include <cstdint>
#include "S_ArmorItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_HelmetItemClass -- KCD2 1.5.6. sizeof 0x120.
// -----------------------------------------------
// E_ItemType::Helmet (16). Vtable 0x183A97EA0, Clone sub_180D2986C alloc 0x120
// (Armor copy-ctor + own dword at +0x118). OnRegister vf[51] is Armor's sub_180970684 verbatim.

namespace wh::entitymodule {

class S_HelmetItemClass : public S_ArmorItemClass {
public:
    S_HelmetItemClass* GetAsHelmetItemClass() override { return this; } // [45]

    std::int32_t _unk118;                        // +0x118  clone-copied dword; role UNVERIFIED
    std::uint8_t _pad11C[4];                     // +0x11C
};
static_assert(sizeof(S_HelmetItemClass) == 0x120, "S_HelmetItemClass must be 0x120 (Clone alloc)");
static_assert(offsetof(S_HelmetItemClass, _unk118) == 0x118, "helmet own dword at 0x118");

}  // namespace wh::entitymodule
