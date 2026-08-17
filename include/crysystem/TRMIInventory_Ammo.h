#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

struct TRMIInventory_Ammo {
    CryStringT<char> m_ammoClass; // +0x00, wire key "AmmoClass"
    std::int32_t m_amount;        // +0x08, wire key "Amount"
    std::uint32_t _pad0C;         // +0x0C
};
static_assert(sizeof(TRMIInventory_Ammo) == 0x10,
              "TRMIInventory_Ammo must be 0x10");
