#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

struct TRMIInventory_EquipmentPack {
    CryStringT<char> m_equipmentPack; // +0x00, wire key "EquipmentPack"
    bool m_add;                       // +0x08, wire key "SetMode"
    bool m_primary;                   // +0x09, wire key "SelectPrimary"
    std::byte _pad0A[6];              // +0x0A
};
static_assert(sizeof(TRMIInventory_EquipmentPack) == 0x10,
              "TRMIInventory_EquipmentPack must be 0x10");
