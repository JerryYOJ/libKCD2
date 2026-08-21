#pragma once
#include <cstddef>
#include <cstdint>
#include "S_ArmorItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_QuickSlotContainerItemClass -- KCD2 1.5.6. sizeof 0x120.
// -----------------------------------------------
// E_ItemType::QuickSlotContainer (19). Vtable 0x183BF4BA0, Clone sub_182A42A28 alloc 0x120
// (Armor copy-ctor + own dword at +0x118). OnRegister vf[51] is Armor's sub_180970684 verbatim.

namespace wh::entitymodule {

class S_QuickSlotContainerItemClass : public S_ArmorItemClass {
public:
    S_QuickSlotContainerItemClass* GetAsQuickSlotContainerItemClass() override { return this; } // [48]

    std::int32_t _unk118;                        // +0x118  clone-copied dword; role UNVERIFIED
    std::uint8_t _pad11C[4];                     // +0x11C
};
static_assert(sizeof(S_QuickSlotContainerItemClass) == 0x120,
              "S_QuickSlotContainerItemClass must be 0x120 (Clone alloc)");
static_assert(offsetof(S_QuickSlotContainerItemClass, _unk118) == 0x118, "QSC own dword at 0x118");

}  // namespace wh::entitymodule
